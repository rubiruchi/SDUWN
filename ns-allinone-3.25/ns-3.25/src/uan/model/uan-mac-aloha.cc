/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 University of Washington
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as 
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Leonard Tracy <lentracy@gmail.com>
 */

#include "uan-mac-aloha.h"
#include "uan-tx-mode.h"
#include "uan-address.h"
#include "ns3/log.h"
#include "uan-phy.h"
#include "uan-header-common.h"
#include "ns3/mac48-address.h"
#include <iostream>
namespace ns3
{

NS_LOG_COMPONENT_DEFINE ("UanMacAloha");
  
NS_OBJECT_ENSURE_REGISTERED (UanMacAloha);

UanMacAloha::UanMacAloha ()
  : UanMac (),
    m_cleared (false)
{
}

UanMacAloha::~UanMacAloha ()
{
}

void
UanMacAloha::Clear ()
{
  if (m_cleared)
    {
      return;
    }
  m_cleared = true;
  if (m_phy)
    {
      m_phy->Clear ();
      m_phy = 0;
    }
}

void
UanMacAloha::DoDispose ()
{
  Clear ();
  UanMac::DoDispose ();
}

TypeId
UanMacAloha::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::UanMacAloha")
    .SetParent<UanMac> ()
    .SetGroupName ("Uan")
    .AddConstructor<UanMacAloha> ()
  ;
  return tid;
}

Address
UanMacAloha::GetMac48Address(void)
{
  Address addr = m_at.getM48(m_address);
  NS_LOG_DEBUG("GetMac48Address: address is " << m_address << "; returning " << addr);
  return addr;
}

Address
UanMacAloha::GetAddress (void)
{
  return m_address;
}

void
UanMacAloha::SetAddress (Address addr)
{
  NS_LOG_DEBUG("SetAddress to " << addr);
  if (Mac48Address::IsMatchingType (addr)){
    m_address = m_at.translate(Mac48Address::ConvertFrom(addr));
    NS_LOG_DEBUG("Translated: " << m_address);
  }
  else
    m_address=UanAddress::ConvertFrom(addr);
}

bool
UanMacAloha::Enqueue (Ptr<Packet> packet, const Address &dest, uint16_t protocolNumber)
{
  UanAddress udest;
  if (Mac48Address::IsMatchingType (dest))
    udest = m_at.translate(Mac48Address::ConvertFrom(dest));
  else
    udest = UanAddress::ConvertFrom (dest);
  NS_LOG_DEBUG ("" << Simulator::Now ().GetSeconds () << " MAC " << UanAddress::ConvertFrom (GetAddress ()) << " Queueing packet for " << udest);
  if (!m_phy->IsStateTx ())
    {
      NS_LOG_DEBUG("UanMacAloha Enqueue: sending packet out");
      UanAddress src = UanAddress::ConvertFrom (GetAddress ());
      UanHeaderCommon header;
      header.SetSrc (src);
      header.SetDest (udest);
      header.SetType (0);
      header.SetLengthType (protocolNumber);
      packet->AddHeader (header);
      m_phy->SendPacket (packet, protocolNumber);
      return true;
    }
  else{
    NS_LOG_DEBUG("UanMacAloha Enqueue: phy is busy, packet may be dropped");
    return false;
  }
}

bool 
UanMacAloha::EnqueueWithSrc(Ptr<Packet> packet, const Address &src, const Address &dest, uint16_t protocolNumber)
{
  UanAddress udest;
  if (Mac48Address::IsMatchingType (dest))
    udest = m_at.translate(Mac48Address::ConvertFrom(dest));
  else
    udest = UanAddress::ConvertFrom (dest);
  NS_LOG_DEBUG ("" << Simulator::Now ().GetSeconds () << " MAC " << UanAddress::ConvertFrom (GetAddress ()) << " Queueing packet for " << udest);
  if (!m_phy->IsStateTx ())
    {
      NS_LOG_DEBUG("UanMacAloha Enqueue: sending packet out");
      UanAddress usrc = UanAddress::ConvertFrom (src);
      UanHeaderCommon header;
      header.SetSrc (usrc);
      header.SetDest (udest);
      header.SetType (0);
      header.SetLengthType (protocolNumber);
      packet->AddHeader (header);
      m_phy->SendPacket (packet, protocolNumber);
      return true;
    }
  else{
    NS_LOG_DEBUG("UanMacAloha Enqueue: phy is busy, packet may be dropped");
    return false;
  }
}


void
UanMacAloha::SetForwardUpCb (Callback<void, Ptr<Packet>, const UanAddress&> cb)
{
  m_forUpCb = cb;
}


void
UanMacAloha::SetPromiscCb (Callback<void, Ptr<Packet>, const Address&, const Address&, uint16_t, NetDevice::PacketType> cb)
{
  m_promiscCb = cb;
}

void
UanMacAloha::AttachPhy (Ptr<UanPhy> phy)
{
  m_phy = phy;
  m_phy->SetReceiveOkCallback (MakeCallback (&UanMacAloha::RxPacketGood, this));
  m_phy->SetReceiveErrorCallback (MakeCallback (&UanMacAloha::RxPacketError, this));
}
void
UanMacAloha::RxPacketGood (Ptr<Packet> pkt, double sinr, UanTxMode txMode){
  UanHeaderCommon header;
  pkt->RemoveHeader (header);
  NS_LOG_DEBUG ("Receiving packet from " << header.GetSrc () << " For " << header.GetDest () << " m_address is " << m_address );
  if (header.GetDest () == GetAddress () || header.GetDest () == UanAddress::GetBroadcast ())
  {
      m_forUpCb (pkt, header.GetSrc ());
  }
  if (pkt->ToString()!=""){
     if (!m_promiscCb.IsNull()){
        NetDevice::PacketType packetType;
        if (header.GetDest () == UanAddress::GetBroadcast ()){
                packetType = NetDevice::PACKET_BROADCAST;
        }
        else if (header.GetDest () == m_address){
                packetType = NetDevice::PACKET_HOST;
        }
        else{
                packetType = NetDevice::PACKET_OTHERHOST;
        }
        m_promiscCb (pkt, m_at.getM48(header.GetSrc()), m_at.getM48(header.GetDest()), header.GetLengthType(), packetType);
      }
   }
}

void
UanMacAloha::RxPacketError (Ptr<Packet> pkt, double sinr)
{
  NS_LOG_DEBUG ("" << Simulator::Now () << " MAC " << UanAddress::ConvertFrom (GetAddress ()) << " Received packet in error with sinr " << sinr);
}

Address
UanMacAloha::GetBroadcast (void) const
{
  UanAddress broadcast (255);
  return broadcast;
}


bool
UanMacAloha::SupportsSendFrom(void) const
{
  return true;
}

int64_t
UanMacAloha::AssignStreams (int64_t stream)
{
  NS_LOG_FUNCTION (this << stream);
  return 0;
}

}

/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
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
 */
//
// String topology, equal distance 
//
//     *---*---*---...---*
//
#include <iostream>
#include <fstream>
// General h files
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/applications-module.h"
#include "ns3/log.h"
#include "ns3/config.h"
#include "ns3/callback.h"
// Uan Module
#include "ns3/uan-module.h"
#include "ns3/stats-module.h"
using namespace ns3;
NS_LOG_COMPONENT_DEFINE ("UanAttenuationExample");
//
// Callback functions for tracing sources
//
// Callback for application
void ReceivePacket (Ptr<Socket> socket)
{
  Ptr<Packet> packet;
  while ((packet = socket->Recv ()))
    {
      NS_LOG_INFO ("Received data: " << packet->GetSize () );
    }
}
// Callbacks for printing tracing sources in UanPhyGen
void PrintRxOk (std::string context, Ptr<const Packet> pkt, double sinr, UanTxMode mode)
{
  NS_LOG_INFO ( Simulator::Now()<< " RX OK with SINR: " << sinr << " dB");
}

void PrintRxError (std::string context, Ptr<const Packet> pkt, double sinr, UanTxMode mode)
{
  NS_LOG_INFO ( Simulator::Now()<< " RX Error with SINR: " << sinr << " dB");
}

void PrintTx (std::string context, Ptr<const Packet> pkt, double sinr, UanTxMode mode)
{
  NS_LOG_INFO ( Simulator::Now()<< " TX with SINR: " << sinr << " dB");
}
// Callbacks for printing tracing sources in UanPhy

void PrintTxBegin (std::string context, Ptr<const Packet> pkt)
{
  NS_LOG_INFO ( Simulator::Now()<< " Start TX" );
}

void PrintTxEnd (std::string context, Ptr<const Packet> pkt)
{
  NS_LOG_INFO ( Simulator::Now()<< " End TX" );
}

void PrintRxBegin (std::string context, Ptr<const Packet> pkt)
{
  NS_LOG_INFO ( Simulator::Now()<< " Start RX" );
}

void PrintRxEnd (std::string context, Ptr<const Packet> pkt)
{
  NS_LOG_INFO ( Simulator::Now()<< " End RX" );
}

void PrintRxDrop (std::string context, Ptr<const Packet> pkt)
{
  NS_LOG_INFO ( Simulator::Now()<< " Packet Dropped" );
}
// Callbacks for calculating packet loss ratio
//
// main function
//
int 
main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);
  //LogComponentEnable("UanChannel", LOG_ALL);
  //LogComponentEnable("UanHelper", LOG_ALL);
  //LogComponentEnable("UanNetDevice", LOG_ALL);
  //LogComponentEnable("UanPhyGen", LOG_ALL);
  //LogComponentEnable("UanPropModelThorp", LOG_ALL);
  //LogComponentEnable("OnOffApplication", LOG_ALL);
  //LogComponentEnable("UanMacAloha",LOG_ALL);
  //LogComponentEnable("UanPhyGen", LOG_ALL);*/
  LogComponentEnable("UanAttenuationExample", LOG_LEVEL_INFO);
  LogComponentEnableAll(LOG_PREFIX_NODE);
  LogComponentEnableAll(LOG_PREFIX_TIME);
  int nNodes = 100;          // number of nodes
  double sPreadCoef = 1.5;   // 1-2, spreading coefficient
  double rxThresh = 5;       // in dB, threshold for receiving a pkt
  double txPower = 140;      // in dB, tx power
  double windspeed = 4.5;    // in m/s, wind speed
  double shipcontri = 0.5;   // 0-1, Shipping contribution to noise
  NodeContainer nodes;
  nodes.Create (nNodes);
  //
  // Here begins the channel module configurations
  //
  UanHelper uan;
  Ptr<UanChannel> chan = CreateObject<UanChannel>();
  // Noise
  Ptr<UanNoiseModelDefault> noise = 
      CreateObjectWithAttributes<UanNoiseModelDefault> (
                                "Wind", DoubleValue(windspeed),
                                "Shipping", DoubleValue(shipcontri)); 
  chan->SetAttribute("NoiseModel",PointerValue(noise));
  //
  // Configure propagation model
  //
  Ptr<UanPropModelThorp> prop = 
      CreateObjectWithAttributes<UanPropModelThorp> ("SpreadCoef",DoubleValue(sPreadCoef)); 
  chan->SetAttribute ("PropagationModel", PointerValue (prop));
  //
  // Configure modulation mode
  //
  UanTxMode mode; 
  mode = UanTxModeFactory::CreateMode (UanTxMode::FSK, // Modulation type
                                       1624, // Data rate in BPS: 1152B / 5.67s
                                       1624, //
                                       24000, // Center Frequency in Hz
                                       6000, // Bandwidth in Hz
                                       2, // Modulation constellation size, 2 for BPSK, 4 for QPSK 
                                       "Default mode"); // String name for this transmission mode
  UanModesList myModes; 
  myModes.AppendMode (mode);
  //
  // Configure the physcial layer module for uan channel.
  //
  std::string perModel = "ns3::UanPhyPerGenDefault"; 
  std::string sinrModel = "ns3::UanPhyCalcSinrDefault"; 
  ObjectFactory obf; 
  
  obf.SetTypeId (perModel); 
  Ptr<UanPhyPer> per = obf.Create<UanPhyPer> (); 
  obf.SetTypeId (sinrModel); 
  Ptr<UanPhyCalcSinr> sinr = obf.Create<UanPhyCalcSinr> ();
  //sinr.SetAttribute()
  uan.SetPhy ("ns3::UanPhyGen", 
              "PerModel", PointerValue (per), 
              "SinrModel", PointerValue (sinr), 
              "SupportedModes", UanModesListValue (myModes),
              "RxThreshold", DoubleValue (rxThresh),
              "TxPower", DoubleValue (txPower)
              ); 

  //
  // Configure the MAC module for uan channel
  //
  uan.SetMac ("ns3::UanMacAloha"); // every nodes transmit at will

  //
  // Install the wireless devices onto our ghost nodes.
  //
  NetDeviceContainer devices = uan.Install (nodes, chan);

  //
  // We need location information since we are talking about wireless communication, so add a
  // constant position to the ghost nodes.
  //
  MobilityHelper mobility;
  Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator> ();


  double mDist = 50;       // in m, distance between nodes in meter
  for (int i = 0; i < nNodes ; i++) {
    positionAlloc->Add (Vector (( i - nNodes / 2) * mDist, 0.0, -10.0));
  }
  mobility.SetPositionAllocator (positionAlloc);
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (nodes); 
  // double depth = -10;
  // double randomX, randomY;
  // Ptr<UniformRandomVariable> urv = CreateObject<UniformRandomVariable> ();
  // positionAlloc->Add (Vector (-1000.0, 0.0, depth));
  // for (int i=0; i<9; i++){
  // randomX = urv->GetValue (-1000,800);
  // randomY = urv->GetValue (-1000,1000);
  // positionAlloc->Add (Vector (-1000.0 + randomX, 0.0 + randomY, depth));
  // }
  // positionAlloc->Add (Vector (1000.0, 0.0, depth));
  // for (int i=0; i<9; i++){
  // randomX = urv->GetValue (-800,1000);
  // randomY = urv->GetValue (-1000,1000);
  // positionAlloc->Add (Vector (1000.0 + randomX, 0.0 + randomY, depth));
  // }
  mobility.SetPositionAllocator (positionAlloc);
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (nodes);
  //
  // Application layer
  //
  PacketSocketHelper pktskth;
  pktskth.Install (nodes);

  PacketSocketAddress socket;
  socket.SetSingleDevice (devices.Get (nNodes-1)->GetIfIndex ());
  socket.SetPhysicalAddress (devices.Get (nNodes-1)->GetAddress ());
  socket.SetProtocol (0);

  OnOffHelper app ("ns3::PacketSocketFactory", Address (socket));
  app.SetAttribute ("OnTime", StringValue ("ns3::ConstantRandomVariable[Constant=1]"));
  app.SetAttribute ("OffTime", StringValue ("ns3::ConstantRandomVariable[Constant=0]"));
  app.SetAttribute ("DataRate", DataRateValue (1300));
  app.SetAttribute ("PacketSize", UintegerValue (1000));

  ApplicationContainer apps = app.Install (nodes.Get(0));
  apps.Start (Seconds (0.5));
  apps.Stop (Seconds (10.5));

  // Interference
  // ApplicationContainer apps2 = app.Install (nodes.Get(20));
  // apps2.Start (Seconds (0.5));
  // apps2.Stop (Seconds (10.5));

  Ptr<Node> sinkNode = nodes.Get (nNodes-1);
  TypeId psfid = TypeId::LookupByName ("ns3::PacketSocketFactory");

  Ptr<Socket> sinkSocket = Socket::CreateSocket (sinkNode, psfid);
  sinkSocket->Bind (socket);
  sinkSocket->SetRecvCallback (MakeCallback (&ReceivePacket));

  //
  // Enabling Tracing
  //
  // UanPhyGen: RxOk, RxError, Tx
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhyGen/RxOk", 
                   MakeCallback (&PrintRxOk) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhyGen/RxError", 
                   MakeCallback (&PrintRxError) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhyGen/Tx", 
                   MakeCallback ( &PrintTx ) );

  // UanPhy: TxBegin, TxEnd, RxBegin, RxEnd, RxDrop
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyTxBegin", 
                   MakeCallback ( &PrintTxBegin ) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyTxEnd", 
                   MakeCallback ( &PrintTxEnd ) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyRxBegin", 
                   MakeCallback ( &PrintRxBegin ) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyRxEnd", 
                   MakeCallback ( &PrintRxEnd ) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyRxDrop", 
                   MakeCallback ( &PrintRxDrop ) );

  //
  // Run the simulation for ten minutes to give the user time to play around
  //
  NS_LOG_INFO ("Run Simulation.");
  Simulator::Stop (Seconds (100.));
  Simulator::Run ();
  Simulator::Destroy ();
}

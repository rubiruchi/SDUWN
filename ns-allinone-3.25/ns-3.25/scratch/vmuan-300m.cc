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
// This is an illustration of how one could use virtualization techniques to
// allow running applications on virtual machines talking over simulated
// networks.
//
// The actual steps required to configure the virtual machines can be rather
// involved, so we don't go into that here.  Please have a look at one of
// our HOWTOs on the nsnam wiki for more details about how to get the 
// system confgured.  For an example, have a look at "HOWTO Use Linux 
// Containers to set up virtual networks" which uses this code as an 
// example.
//
// The configuration you are after is explained in great detail in the 
// HOWTO, but looks like the following:
//
//  +----------+                           +----------+
//  | virtual  |                           | virtual  |
//  |  Linux   |                           |  Linux   |
//  |   Host   |                           |   Host   |
//  |          |                           |          |
//  |   eth0   |                           |   eth0   |
//  +----------+                           +----------+
//       |                                      |
//  +----------+                           +----------+
//  |  Linux   |                           |  Linux   |
//  |  Bridge  |                           |  Bridge  |
//  +----------+                           +----------+
//       |                                      |
//  +------------+                       +-------------+
//  | "tap-left" |                       | "tap-right" |
//  +------------+                       +-------------+
//       |           n0            n1           |
//       |       +--------+    +--------+       |
//       +-------|  tap   |    |  tap   |-------+
//               | bridge |    | bridge |
//               +--------+    +--------+
//               |  uan   |    |  uan   |
//               +--------+    +--------+
//                   |             |
//                 ((*))         ((*))
//
//
//
#include <iostream>
#include <fstream>

// General h files
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"

// Tap Bridge Module
#include "ns3/tap-bridge-module.h"

// Uan Module
#include "ns3/uan-module.h"
#include "ns3/applications-module.h"
#include "ns3/log.h"
#include "ns3/config.h"
#include "ns3/callback.h"
#include "ns3/stats-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("TapUanVM2Km");

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

int 
main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);
  LogComponentEnable ("TapUanVM2Km", LOG_LEVEL_INFO);
 // LogComponentEnable ("UanPhyGen", LOG_ALL);

  LogComponentEnableAll(LOG_PREFIX_NODE);
  LogComponentEnableAll(LOG_PREFIX_TIME);
  //
  // We are interacting with the outside, real, world.  This means we have to 
  // interact in real-time and therefore means we have to use the real-time
  // simulator and take the time to calculate checksums.
  //
  GlobalValue::Bind ("SimulatorImplementationType", StringValue ("ns3::RealtimeSimulatorImpl"));
  GlobalValue::Bind ("ChecksumEnabled", BooleanValue (true));

  //
  // Create two ghost nodes.  The first will represent the virtual machine host
  // on the left side of the network; and the second will represent the VM on 
  // the right side.
  //
  NodeContainer nodes;
  nodes.Create (3);

  //
  // Here begins the channel module configurations
  //
  double sPreadCoef = 1.5;  // 1-2, spreading coefficient
  double rxThresh = 5;     // in dB, threshold for receiving a pkt
  double txPower = 135;     // in dB, tx power
  double windspeed = 4.5;       // in m/s, wind speed
  double shipcontri = 0.5;       // 0-1, Shipping contribution to noise
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
                                       2264, // Data rate in bps: 1152B / 4.07s
                                       2264, //
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
  positionAlloc->Add (Vector (0.0, 0.0, 0.0));
  positionAlloc->Add (Vector (300.0, 0.0, 0.0));
  positionAlloc->Add (Vector (150.0, 260.0, 0.0));

  mobility.SetPositionAllocator (positionAlloc);
  mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");
  mobility.Install (nodes);

  //
  // Use the TapBridgeHelper to connect to the pre-configured tap devices for 
  // the left side.  We go with "UseLocal" mode since the wifi devices do not
  // support promiscuous mode (because of their natures0.  This is a special
  // case mode that allows us to extend a linux bridge into ns-3 IFF we will
  // only see traffic from one other device on that bridge.  That is the case
  // for this configuration.
  //
  TapBridgeHelper tapBridge;
  tapBridge.SetAttribute ("Mode", StringValue ("UseLocal"));
  tapBridge.SetAttribute ("DeviceName", StringValue ("tap-vNode1"));
  tapBridge.Install (nodes.Get (0), devices.Get (0));

  tapBridge.SetAttribute ("DeviceName", StringValue ("tap-vNode2"));
  tapBridge.Install (nodes.Get (1), devices.Get (1));

  tapBridge.SetAttribute ("DeviceName", StringValue ("tap-vNode3"));
  tapBridge.Install (nodes.Get (2), devices.Get (2));

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
//  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyTxBegin", 
//                   MakeCallback ( &PrintTxBegin ) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyTxEnd", 
                   MakeCallback ( &PrintTxEnd ) );
  Config::Connect ("/NodeList/*/DeviceList/*/$ns3::UanNetDevice/Phy/$ns3::UanPhy/PhyRxBegin", 
                   MakeCallback ( &PrintRxBegin ) );
  //
  //
  //Simulator::Stop (Seconds (600.));
  Simulator::Run ();
  Simulator::Destroy ();
}

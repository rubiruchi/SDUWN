#!/usr/bin/python
from mininet.net import Mininet
from mininet.node import Node, Switch, RemoteController, OVSSwitch, Controller
from mininet.link import Link, Intf
from mininet.log import setLogLevel, info
from mininet.node import RemoteController
from mininet.cli import CLI
import opennet
from opennet import *
import ns
import time
import os

class InbandController( RemoteController ):

    def checkListening( self ):
        "Overridden to do nothing."
        return

def fakeInterfaceDown():
	os.system("ifconfig lo:1 down")

def fakeInterfaceUp():
	os.system("ifconfig lo:1 10.0.0.4/32")

def emptyNet():
    #ns.core.LogComponentEnable("UanChannel", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanHelper",  ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanNetDevice", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanPhyGen", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TagBuffer", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapBridge", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapBridgeHelper", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapFdNetDeviceHelper", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanPhy", ns.core.LOG_ALL)
    #ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_NODE)
    #ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_TIME)
    "Create an empty network and add nodes to it."
    net = Mininet( topo=None,
                   build=False)

    net.addController( 'c0',
                       controller=RemoteController,
                       ip='10.0.0.4', port=6633)

    h1 = net.addHost( 'h1', ip='10.0.0.1' )
    h2 = net.addHost( 'h2', ip='10.0.0.2' )
    h3 = net.addHost( 'h3', ip='10.0.0.3' )
    h5 = net.addHost( 'h5', ip='10.0.0.5' )

    h4 = net.addHost( 'h4', ip='10.0.0.4' )

    s1 = net.addSwitch( 's1', cls=OVSSwitch, inband=True )
    s2 = net.addSwitch( 's2', cls=OVSSwitch, inband=True )
    s3 = net.addSwitch( 's3', cls=OVSSwitch, inband=True )
    s5 = net.addSwitch( 's5', cls=OVSSwitch, inband=True )
    
    net.addLink( h1, s1 )
    net.addLink( h2, s2 )
    net.addLink( h3, s3 )
    net.addLink( h5, s5 )
    
    Csma = CSMASegment(DataRate="10Mbps", Delay="100000000ns")
    Csma.add(h4)
    Csma.add(s1)
    Csma.add(s2)
    Csma.add(s3)
    Csma.add(s5)

    uanSH = UanSegment(ns.uan.UanTxMode.FSK, 8300608, 8300608, 300000, 200000, 6, "Default mode", 0, 0, 0)
    uanSH.add(s1)
    uanSH.add(s2)
    uanSH.add(s3)
    uanSH.add(s5)

    mobility_helpers={'h1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h3':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h4':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h5':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's3':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's5':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel")
                     }

    list_position={'h1':opennet.createListPositionAllocate(x1=0,y1=50,z1=-10),
                    'h2':opennet.createListPositionAllocate(x1=0,y1=100,z1=-10),
                    'h3':opennet.createListPositionAllocate(x1=0,y1=150,z1=-10),
                    'h4':opennet.createListPositionAllocate(x1=0,y1=0,z1=-10),
                    'h5':opennet.createListPositionAllocate(x1=0,y1=200,z1=-10),
                    's1':opennet.createListPositionAllocate(x1=0,y1=51,z1=-10),
                    's2':opennet.createListPositionAllocate(x1=0,y1=101,z1=-10),
                    's3':opennet.createListPositionAllocate(x1=0,y1=151,z1=-10),
                    's5':opennet.createListPositionAllocate(x1=0,y1=201,z1=-10)
                  }

    mobility_models={'h1': opennet.setListPositionAllocate(mobility_helpers['h1'],
                                                               list_position['h1']
                                            ),
                     'h2': opennet.setListPositionAllocate(mobility_helpers['h2'],
                                                               list_position['h2']
                                            ),
                     'h3': opennet.setListPositionAllocate(mobility_helpers['h3'],
                                                               list_position['h3']
                                            ),
                     'h4': opennet.setListPositionAllocate(mobility_helpers['h4'],
                                                               list_position['h4']
                                            ),
                     'h5': opennet.setListPositionAllocate(mobility_helpers['h5'],
                                                               list_position['h5']
                                            ),
                     's1': opennet.setListPositionAllocate(mobility_helpers['s1'],
                                                               list_position['s1']
                                            ),
                     's2': opennet.setListPositionAllocate(mobility_helpers['s2'],
                                                               list_position['s2']
                                            ),
                     's3': opennet.setListPositionAllocate(mobility_helpers['s3'],
                                                               list_position['s3']
                                            ),
                     's5': opennet.setListPositionAllocate(mobility_helpers['s5'],
                                                               list_position['s5']
                                            )
    }
    opennet.setMobilityModel(h1, mobility_models.get('h1'))
    opennet.setMobilityModel(h2, mobility_models.get('h2'))
    opennet.setMobilityModel(h3, mobility_models.get('h3'))
    opennet.setMobilityModel(h4, mobility_models.get('h4'))
    opennet.setMobilityModel(h5, mobility_models.get('h5'))
    opennet.setMobilityModel(s1, mobility_models.get('s1'))
    opennet.setMobilityModel(s2, mobility_models.get('s2'))
    opennet.setMobilityModel(s3, mobility_models.get('s3'))
    opennet.setMobilityModel(s5, mobility_models.get('s5'))
    
    net.start()
    opennet.start()
    #s1.cmd('ifconfig s1 10.0.0.10')
    #s2.cmd('ifconfig s2 10.0.0.11')
    #s3.cmd('ifconfig s3 10.0.0.12')
    CLI( net )
    net.stop()

if __name__ == '__main__':
    setLogLevel( 'debug' )
    emptyNet()

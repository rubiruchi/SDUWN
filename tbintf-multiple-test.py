from mininet.net import Mininet
from mininet.node import Node, Switch, RemoteController
from mininet.link import Link, Intf
from mininet.log import setLogLevel, info
from mininet.node import RemoteController
from mininet.cli import CLI
import opennet
from opennet import *
import ns
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
    net = Mininet()
    net.addController('c0', controller=RemoteController, ip="127.0.0.1", port=6634)

    info( '*** Adding hosts\n' )
    h0 = net.addHost( 'h0' )
    h1 = net.addHost( 'h1' )
    h2 = net.addHost( 'h2' )

    s0 = net.addSwitch( 's0', ip=None, failMode='standalone')
    s1 = net.addSwitch( 's1', ip=None, failMode='standalone')
    s2 = net.addSwitch( 's2', ip=None, failMode='standalone' )
    
    info( '*** Creating links\n' )
    Uan=UanSegment()
    Uan.add(s0)
    Uan.add(s1)
    Uan.add(s2)

    link0=CSMALink(s0,h0)
    link1=CSMALink(s1,h1)
    link2=CSMALink(s2,h2)
    
    mobility_helpers={'h0':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's0':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel")
                     }
    list_position={'h0':opennet.createListPositionAllocate(x1=0,y1=30,z1=-10),
                    'h1':opennet.createListPositionAllocate(x1=0,y1=-10,z1=-10),
                    'h2':opennet.createListPositionAllocate(x1=30,y1=0,z1=-10),
                    's0':opennet.createListPositionAllocate(x1=0,y1=20,z1=-10),
                    's1':opennet.createListPositionAllocate(x1=0,y1=0,z1=-10),
                    's2':opennet.createListPositionAllocate(x1=20,y1=0,z1=-10)
                  }
    mobility_models={'h0': opennet.setListPositionAllocate(mobility_helpers['h0'],
                                                           list_position['h0']
                                            ),
                     'h1': opennet.setListPositionAllocate(mobility_helpers['h1'],
                                                               list_position['h1']
                                            ),
                     'h2': opennet.setListPositionAllocate(mobility_helpers['h2'],
                                                               list_position['h2']
                                            ),
                     's0': opennet.setListPositionAllocate(mobility_helpers['s0'],
                                                               list_position['s0']
                                            ),
                     's1': opennet.setListPositionAllocate(mobility_helpers['s1'],
                                                               list_position['s1']
                                            ),
                     's2': opennet.setListPositionAllocate(mobility_helpers['s2'],
                                                               list_position['s2']
                                            )
    }
    opennet.setMobilityModel(h0, mobility_models.get('h0'))
    opennet.setMobilityModel(h1, mobility_models.get('h1')) 
    opennet.setMobilityModel(h2, mobility_models.get('h2')) 
    opennet.setMobilityModel(s0, mobility_models.get('s0'))
    opennet.setMobilityModel(s1, mobility_models.get('s1'))
    opennet.setMobilityModel(s2, mobility_models.get('s2')) 

    info( '*** Configuring hosts\n' )
    h0.setIP( '192.168.123.1/24')
    h1.setIP( '192.168.123.2/24')
    h2.setIP( '192.168.123.3/24')

    info( '*** Starting network\n')
    opennet.start()
    info( '*** Running CLI\n' )
    CLI( net )
if __name__ == '__main__':
    setLogLevel( 'info' )
    emptyNet()

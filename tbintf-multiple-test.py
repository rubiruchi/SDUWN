from mininet.net import Mininet
from mininet.node import Node, Switch, RemoteController
from mininet.link import Link, Intf
from mininet.log import setLogLevel, info
from mininet.node import RemoteController
from mininet.cli import CLI
import opennet
from opennet import *
import ns
def main():
    info( '*** Adding controller\n' )
    #ns.core.LogComponentEnable("UanChannel", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanHelper",  ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanNetDevice", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanPhyGen", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TagBuffer", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapBridge", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapBridgeHelper", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapFdNetDeviceHelper", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanPhy", ns.core.LOG_ALL)
    ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_NODE)
    ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_TIME)

    net = Mininet()

    info( '*** Adding controller\n' )
    net.addController('c0', controller=RemoteController, ip="127.0.0.1", port=6655)
    

    info( '*** Adding hosts\n' )
    h0 = net.addHost( 'h0' ,ip = '192.168.123.1')
    h1 = net.addHost( 'h1' ,ip = '192.168.123.2')
    
    info( '*** Adding switch\n')
    s0 = net.addSwitch( 's0' )
    
    info( '*** Creating links\n' )
    
    #Uan=UanSegment()
    #Uan.add(h0)
    #Uan.add(h1)
    
    link0=UanLink(s0,h0)
    link1=UanLink(s0,h1)
    
    mobility_helpers={'h0':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's0':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel")
                     }
    list_position={'h0':opennet.createListPositionAllocate(x1=0,y1=30,z1=-10),
                    'h1':opennet.createListPositionAllocate(x1=0,y1=0,z1=-10),
                    's0':opennet.createListPositionAllocate(x1=30,y1=0,z1=-10)
                  }
    mobility_models={'h0': opennet.setListPositionAllocate(mobility_helpers['h0'],
                                                           list_position['h0']
                                            ),
                     'h1': opennet.setListPositionAllocate(mobility_helpers['h1'],
                                                               list_position['h1']
                                            ),
                     's0': opennet.setListPositionAllocate(mobility_helpers['s0'],
                                                               list_position['s0']
                                            )
    }
    opennet.setMobilityModel(h0, mobility_models.get('h0'))
    opennet.setMobilityModel(h1, mobility_models.get('h1')) 
    opennet.setMobilityModel(s0, mobility_models.get('s0'))  

    #info( '*** Configuring hosts\n' )
    #h0.setIP( '192.168.123.1/24')
    #h1.setIP( '192.168.123.2/24')

    info( '*** Starting network\n')
    net.start()
    opennet.start()
    
    info( '*** Running CLI\n' )
    CLI( net )

    info( '*** Stopping network')
    opennet.clear()
    net.stop()
if __name__ == '__main__':
    setLogLevel( 'info' )
    main()

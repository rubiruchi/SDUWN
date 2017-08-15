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
def main():
    net = Mininet()
    info( '*** Adding hosts\n' )
    h0 = net.addHost( 'h0' ,ip = '192.168.123.1')
    #h1 = net.addHost( 'h1' ,ip = '192.168.123.2')
    #h2 = net.addHost( 'h2' ,ip = '192.168.123.3')
    info( '*** Adding switch\n')
    s0 = net.addSwitch( 's0' )
    #s1 = net.addSwitch( 's1' )
    #s2 = net.addSwitch( 's2' )
    info( '*** Creating links\n' )    
    net.addLink(s0,h0)
    #net.addLink(s1,h1)
    #net.addLink(s2,h2)
    Csma=CSMASegment()
    Csma.add(s0)
    #csma.add(s1)
    #csma.add(s2)
    
    info( '*** Adding controller\n' )
    Csma.addController("tap-left")
    

    mobility_helpers={'h0':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     'h2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's0':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                     's2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel")
                     }

    list_position={'h0':opennet.createListPositionAllocate(x1=0,y1=15,z1=-10),
                    'h1':opennet.createListPositionAllocate(x1=-5,y1=-5,z1=-10),
                    'h2':opennet.createListPositionAllocate(x1=15,y1=0,z1=-10),
                    's0':opennet.createListPositionAllocate(x1=0,y1=10,z1=-10),
                    's1':opennet.createListPositionAllocate(x1=0,y1=0,z1=-10),
                    's2':opennet.createListPositionAllocate(x1=10,y1=0,z1=-10)
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
    #opennet.setMobilityModel(h1, mobility_models.get('h1'))  
    #opennet.setMobilityModel(h2, mobility_models.get('h2'))
    opennet.setMobilityModel(s0, mobility_models.get('s0'))
    #opennet.setMobilityModel(s1, mobility_models.get('s1'))
    #opennet.setMobilityModel(s2, mobility_models.get('s2'))
    info( '*** Starting network\n')
    net.build()
    

    info( '*** Sleeping\n')
    time.sleep(10)
    

    net.addController("c0",controller=RemoteController,ip="192.168.123.13",port=6653)
    
    net.start()
    opennet.start()
    
    info( '*** Running CLI\n' )
    CLI( net )

    info( '*** Stopping network')
    opennet.clear()
    net.stop()

if __name__ == '__main__':
    setLogLevel( 'debug' )
    main()

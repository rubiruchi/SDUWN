from mininet.net import Mininet
from mininet.node import Node, Switch
from mininet.link import Link, Intf
from mininet.log import setLogLevel, info
from mininet.cli import CLI
import opennet
from opennet import *
import ns
if __name__ == '__main__':
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
    setLogLevel( 'info' )
    info( '*** ns-3 network demo\n' )
    net = Mininet()

    info( '*** Creating Network\n' )
    h0 = net.addHost( 'h0' )
    h1 = net.addHost( 'h1' )
    link = UanLink( h0, h1 )
    mobility_helpers = {'h0': opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                        'h1': opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel")
                       }

    list_position = {'h0': opennet.createListPositionAllocate(x1=0,y1=10,z1=-10),
                     'h1': opennet.createListPositionAllocate(x1=50,y1=0,z1=-10)
                    }

    """ Mobility models of hosts """
    mobility_models = {'h0': opennet.setListPositionAllocate(mobility_helpers['h0'],
                                                                 list_position['h0']
                                                                ),
                       'h1': opennet.setListPositionAllocate(mobility_helpers['h1'],
                                                                 list_position['h1']
                                                                )
                      }


    opennet.setMobilityModel(h0, mobility_models.get('h0'))
    opennet.setMobilityModel(h1, mobility_models.get('h1'))
    
    print opennet.getPosition(h0)
    print opennet.getPosition(h1)



#   NS part ------------------------------------------------------

    #link = CSMALink( h0, h1 )

#   NS part END --------------------------------------------------
    info( '*** Configuring hosts\n' )
    h0.setIP( '192.168.123.1/24' )
    h1.setIP( '192.168.123.2/24')

    opennet.start()
    info( '*** Network state:\n' )
    for node in h0, h1:
        info( str( node ) + '\n' )

    info( '*** Running test\n' )
    h0.cmdPrint( 'ping -c1 ' + h1.IP() )
    CLI(net)

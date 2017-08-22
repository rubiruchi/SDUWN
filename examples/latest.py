from mininet.net import Mininet
from mininet.node import Node, Switch, RemoteController, OVSSwitch, Controller
from mininet.link import Link, Intf
from mininet.log import setLogLevel, info
from mininet.node import RemoteController
from mininet.cli import CLI
import opennet
from opennet import *
import ns, time, os, datetime, ntpath

def main():
    #ns.core.LogComponentEnable("UanChannel", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanHelper", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanNetDevice", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanPhyGen", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TagBuffer", ns.core.LOG_ALL) 
    #ns.core.LogComponentEnable("TapBridge", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapBridgeHelper", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("TapFdNetDeviceHelper", ns.core.LOG_ALL)
    #ns.core.LogComponentEnable("UanPhy", ns.core.LOG_ALL)
    #ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_NODE) 
    #ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_TIME)
    net = Mininet(topo=None,
                   build=False)
    #net = Mininet(switch=MultiSwitch, build=False)
    net.addController( 'c0',
                       controller=RemoteController,
                       ip='10.0.0.4', port=6653)
    
    h1 = net.addHost( 'h1' ,ip = '10.0.0.1')
    h2 = net.addHost( 'h2' ,ip = '10.0.0.2')
    
    h4 = net.addHost( 'h4' ,ip = '10.0.0.4')

    s1 = net.addSwitch( 's1', cls=OVSSwitch, inband=True )
    s2 = net.addSwitch( 's2', cls=OVSSwitch, inband=True )

    net.addLink(s1,h1)
    net.addLink(s2,h2)

    #uanLL = UanSegment(ns.uan.UanTxMode.FSK, 10000, 10000, 24000, 6000, 2, "Default mode", 0, 0, 1)
    uanLL = CSMASegment()
    uanLL.add(h4)
    uanLL.add(s1)
    uanLL.add(s2)

    #uanSH = UanSegment(ns.uan.UanTxMode.FSK, 8300608, 8300608, 300000, 200000, 6, "Default mode", 0, 0, 0)
    uanSH = CSMASegment()
    uanSH.add(s1)
    uanSH.add(s2)

    mobility_helpers={
                      'h1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                      'h2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                      'h3':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                      'h4':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                      's1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
                      's2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
		                  's3':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel")
                     }

    list_position={
                   'h1':opennet.createListPositionAllocate(x1=5,y1=0,z1=-10),
                   'h2':opennet.createListPositionAllocate(x1=10,y1=0,z1=-10),
                   'h3':opennet.createListPositionAllocate(x1=15,y1=0,z1=-10),
                   'h4':opennet.createListPositionAllocate(x1=0,y1=0,z1=-10),
                   's1':opennet.createListPositionAllocate(x1=4,y1=0,z1=-10),
                   's2':opennet.createListPositionAllocate(x1=9,y1=0,z1=-10),
		               's3':opennet.createListPositionAllocate(x1=14,y1=0,z1=-10)
                  }

    mobility_models={
                     'h1': opennet.setListPositionAllocate(mobility_helpers['h1'],
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
                     's1': opennet.setListPositionAllocate(mobility_helpers['s1'],
                                                               list_position['s1']
                                            ),
                     's2': opennet.setListPositionAllocate(mobility_helpers['s2'],
                                                               list_position['s2']
                                            ),
		                 's3': opennet.setListPositionAllocate(mobility_helpers['s3'],
							                                   list_position['s3'])
    }
    
    opennet.setMobilityModel(h1, mobility_models.get('h1'))
    opennet.setMobilityModel(h2, mobility_models.get('h2'))
    #opennet.setMobilityModel(h3, mobility_models.get('h3'))
    opennet.setMobilityModel(h4, mobility_models.get('h4'))
    opennet.setMobilityModel(s1, mobility_models.get('s1'))
    opennet.setMobilityModel(s2, mobility_models.get('s2'))
    #opennet.setMobilityModel(s3, mobility_models.get('s3'))

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
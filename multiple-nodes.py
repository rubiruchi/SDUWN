from mininet.net import Mininet
from mininet.node import Node, Switch
from mininet.link import Link, Intf
from mininet.log import setLogLevel, info
from mininet.cli import CLI
import opennet
from opennet import *
import ns
if __name__ == '__main__':
	setLogLevel('info')
	info('*** App Module with Multiple Nodes\n')
	net=Mininet()

	info('*** Creating Network\n')
	h0=net.addHost('h0')
	h1=net.addHost('h1')
	h2=net.addHost('h2')

	s0=net.addSwitch('s0')
	s1=net.addSwitch('s1')
	s2=net.addSwitch('s2')
	net.addLink(s0,h0)
	net.addLink(s1,h1)
	net.addLink(s2,h2)
	#link1=UanLink(s0,h0)
	#link2=UanLink(s1,h1)
	#link3=UanLink(s2,h2)
	link4=UanLink(s0,s1)
	link5=UanLink(s0,s2)
	mobility_helpers={'h0':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
					'h1':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel"),
					'h2':opennet.createMobilityHelper("ns3::ConstantPositionMobilityModel")
					}
	list_position={'h0':opennet.createListPositionAllocate(x1=0,y1=70,z1=-10),
					'h1':opennet.createListPositionAllocate(x1=0,y1=-20,z1=-10),
					'h2':opennet.createListPositionAllocate(x1=70,y1=0,z1=-10)
					}
	mobility_models={'h0': opennet.setListPositionAllocate(mobility_helpers['h0'],
																list_position['h0']
																),
					'h1': opennet.setListPositionAllocate(mobility_helpers['h1'],
																list_position['h1']
																),
					'h2':opennet.setListPositionAllocate(mobility_helpers['h2'],
																list_position['h2']
																)
					}
	positions = {'s0': (0, 50, -10),
				's1': (0, 0, -10),
				's2': (50, 0, -10)
				}
	opennet.setMobilityModel(h0, mobility_models.get('h0'))
	opennet.setMobilityModel(h1, mobility_models.get('h1'))
	opennet.setMobilityModel(h2, mobility_models.get('h2')) 

	opennet.setMobilityModel(s0,None)
	opennet.setMobilityModel(s1,None)
	opennet.setMobilityModel(s2,None)

	pos_tuple=positions.get('s0')
	opennet.setPosition(s0,pos_tuple[0],pos_tuple[1],pos_tuple[2])
	pos_tuple=positions.get('s1')
	opennet.setPosition(s1,pos_tuple[0],pos_tuple[1],pos_tuple[2])
	pos_tuple=positions.get('s2')
	opennet.setPosition(s2,pos_tuple[0],pos_tuple[1],pos_tuple[2])

	print opennet.getPosition(h0)
	print opennet.getPosition(h1)
	print opennet.getPosition(h2)
	print opennet.getPosition(s0)
	print opennet.getPosition(s1)
	print opennet.getPosition(s2)

	info('*** Configuring hosts\n')
	h0.setIP('192.168.123.1/24')
	h1.setIP('192.168.123.2/24')
	h2.setIP('192.168.123.3/24')

	opennet.start()

	info('*** Network state:\n')
	for node in h0,h1,h2:
		info(str(node)+'\n')
	info('*** Running test\n')

	net.pingAll()
	CLI(net)
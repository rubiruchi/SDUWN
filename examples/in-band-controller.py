#!/usr/bin/python

from mininet.net import Mininet
from mininet.node import RemoteController, OVSSwitch
from mininet.cli import CLI
from mininet.log import setLogLevel, info

class InbandController( RemoteController ):

    def checkListening( self ):
        "Overridden to do nothing."
        return

def emptyNet():

    "Create an empty network and add nodes to it."

    net = Mininet( topo=None,
                   build=False)

    net.addController( 'c0',
                       controller=InbandController,
                       ip='10.0.0.4', port=6653)

    h1 = net.addHost( 'h1', ip='10.0.0.1' )
    h2 = net.addHost( 'h2', ip='10.0.0.2' )
    h3 = net.addHost( 'h3', ip='10.0.0.3' )
    h4 = net.addHost( 'h4', ip='10.0.0.4' )
    h5 = net.addHost( 'h5', ip='10.0.0.5' )

    s1 = net.addSwitch( 's1', cls=OVSSwitch )
    s2 = net.addSwitch( 's2', cls=OVSSwitch )
    s3 = net.addSwitch( 's3', cls=OVSSwitch )
    
    net.addLink( h1, s1 )
    net.addLink( h2, s2 )
    net.addLink( h3, s3 )
    net.addLink( h5, s1 ) 
    net.addLink( h4, s1 )
    net.addLink( h4, s2 )
    net.addLink( h4, s3 )
    net.addLink( s1, s2 )
    net.addLink( s2, s3 )

    net.start()
    s1.cmd('ifconfig s1 10.0.0.10')
    s2.cmd('ifconfig s2 10.0.0.11')
    s3.cmd('ifconfig s3 10.0.0.12')

    CLI( net )
    net.stop()

if __name__ == '__main__':
    setLogLevel( 'debug' )
    emptyNet()

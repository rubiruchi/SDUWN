#! /bin/sh

# liwei@mtu.edu
# Date: 04/20/2017. Version 1.0

# setup tap bridge and devices

name=vNode1
ip=1

sudo brctl addbr br-$name
sudo tunctl -t tap-$name
sudo ifconfig tap-$name mtu 8192
sudo ifconfig tap-$name 0.0.0.0 promisc up
sudo brctl addif br-$name tap-$name
sudo ip addr add 10.1.1.$ip/24 dev br-$name
sudo ip route add 10.1.1.0/24 dev br-$name
sudo ifconfig br-$name mtu 8192
sudo ifconfig br-$name up

name=vNode2
ip=2

sudo brctl addbr br-$name
sudo tunctl -t tap-$name
sudo ifconfig tap-$name mtu 8192
sudo ifconfig tap-$name 0.0.0.0 promisc up
sudo brctl addif br-$name tap-$name
sudo ip addr add 10.1.1.$ip/24 dev br-$name
sudo ip route add 10.1.1.0/24 dev br-$name
sudo ifconfig br-$name mtu 8192
sudo ifconfig br-$name up

name=vNode3
ip=3

sudo brctl addbr br-$name
sudo tunctl -t tap-$name
sudo ifconfig tap-$name mtu 8192
sudo ifconfig tap-$name 0.0.0.0 promisc up
sudo brctl addif br-$name tap-$name
sudo ip addr add 10.1.1.$ip/24 dev br-$name
sudo ip route add 10.1.1.0/24 dev br-$name
sudo ifconfig br-$name mtu 8192
sudo ifconfig br-$name up

name=vNode4
ip=4

sudo brctl addbr br-$name
sudo tunctl -t tap-$name
sudo ifconfig tap-$name mtu 8192
sudo ifconfig tap-$name 0.0.0.0 promisc up
sudo brctl addif br-$name tap-$name
sudo ip addr add 10.1.1.$ip/24 dev br-$name
sudo ip route add 10.1.1.0/24 dev br-$name
sudo ifconfig br-$name mtu 8192
sudo ifconfig br-$name up

name=vNode5
ip=5

sudo brctl addbr br-$name
sudo tunctl -t tap-$name
sudo ifconfig tap-$name mtu 8192
sudo ifconfig tap-$name 0.0.0.0 promisc up
sudo brctl addif br-$name tap-$name
sudo ip addr add 10.1.1.$ip/24 dev br-$name
sudo ip route add 10.1.1.0/24 dev br-$name
sudo ifconfig br-$name mtu 8192
sudo ifconfig br-$name up

name=vNode6
ip=6

sudo brctl addbr br-$name
sudo tunctl -t tap-$name
sudo ifconfig tap-$name mtu 8192
sudo ifconfig tap-$name 0.0.0.0 promisc up
sudo brctl addif br-$name tap-$name
sudo ip addr add 10.1.1.$ip/24 dev br-$name
sudo ip route add 10.1.1.0/24 dev br-$name
sudo ifconfig br-$name mtu 8192
sudo ifconfig br-$name up

ifconfig -a
sudo brctl show

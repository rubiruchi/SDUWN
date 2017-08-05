#! /bin/sh
# setup tap bridge and devices

tap=tap-left
bridge=br-left
ipaddr=192.168.123.11
iproute=192.168.123.0

sudo tunctl -t $tap 
sudo ip link set up dev $tap 
sudo brctl addbr $bridge 
sudo brctl addif $bridge $tap 
sudo ip link set up dev $bridge
sudo ip addr add $ipaddr/24 dev $bridge
sudo ip route add $iproute/24 dev $bridge

tap=tap-right
bridge=br-right
ipaddr=192.168.123.12
iproute=192.168.123.0

sudo tunctl -t $tap 
sudo ip link set up dev $tap 
sudo brctl addbr $bridge 
sudo brctl addif $bridge $tap 
sudo ip link set up dev $bridge
sudo ip addr add $ipaddr/24 dev $bridge
sudo ip route add $iproute/24 dev $bridge

ifconfig -a
sudo brctl show

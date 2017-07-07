#!/bin/sh

# assign the tap devices
tap1=tap-vNode1
tap2=tap-vNode2
tap3=tap-vNode3
tap4=tap-vNode4
tap5=tap-vNode5
tap6=tap-vNode6

# assign the tap bridges
bridge1=br-vNode1
bridge2=br-vNode2
bridge3=br-vNode3
bridge4=br-vNode4
bridge5=br-vNode5
bridge6=br-vNode6


sudo ifconfig $bridge1 down 
sudo brctl delif $bridge1 $tap1 
sudo brctl delbr $bridge1 
sudo ifconfig $tap1 down 
sudo tunctl -d $tap1

sudo ifconfig $bridge2 down 
sudo brctl delif $bridge2 $tap2 
sudo brctl delbr $bridge2 
sudo ifconfig $tap2 down 
sudo tunctl -d $tap2 

sudo ifconfig $bridge3 down 
sudo brctl delif $bridge3 $tap3 
sudo brctl delbr $bridge3 
sudo ifconfig $tap3 down 
sudo tunctl -d $tap3 

sudo ifconfig $bridge4 down 
sudo brctl delif $bridge4 $tap4 
sudo brctl delbr $bridge4 
sudo ifconfig $tap4 down 
sudo tunctl -d $tap4 

sudo ifconfig $bridge5 down 
sudo brctl delif $bridge5 $tap5 
sudo brctl delbr $bridge5 
sudo ifconfig $tap5 down 
sudo tunctl -d $tap5 

sudo ifconfig $bridge6 down 
sudo brctl delif $bridge6 $tap6 
sudo brctl delbr $bridge6 
sudo ifconfig $tap6 down 
sudo tunctl -d $tap6 

sudo brctl show
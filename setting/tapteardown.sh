
tap=tap-left
bridge=br-left

sudo ifconfig $bridge down 
sudo brctl delif $bridge $tap 
sudo brctl delbr $bridge 
sudo ifconfig $tap down 
sudo tunctl -d $tap 

tap=tap-right
bridge=br-right

sudo ifconfig $bridge down 
sudo brctl delif $bridge $tap 
sudo brctl delbr $bridge 
sudo ifconfig $tap down 
sudo tunctl -d $tap 

sudo brctl show

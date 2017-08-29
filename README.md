## SDUWN

#### Environment Configuration
1.Disable IPv6 for preventing TAP devices/bridges broadcasting routing:

- **Step 1:** Edit `/etc/sysctl.conf` (with sudo) and open the configuration file and add the following lines at the end:

```
net.ipv6.conf.all.disable_ipv6 = 1
net.ipv6.conf.default.disable_ipv6 = 1
net.ipv6.conf.lo.disable_ipv6 = 1
```

- **Step 2:** Type command `sudo sysctl -p` you will see this in terminal.
```
net.ipv6.conf.all.disable_ipv6 = 1
net.ipv6.conf.default.disable_ipv6 = 1
net.ipv6.conf.lo.disable_ipv6 = 1
```

- **Step 3:** After that run `$ cat /proc/sys/net/ipv6/conf/all/disable_ipv6`
If it reports ‘1′ means you have disabled IPV6. 
If it reports ‘0‘ then please follow Step 2.

2.Compile Mininet

- **Step 1:** Move the `opennet-agent.py` into `/usr/bin/`:
```
sudo chmod 777 opennet-agent.py
sudo mv opennet-agent.py /usr/bin/
```
- **Step 2:** Install Mininet
```
./mininet/util/install.sh -a
```
You might need to delete `pox/` and `openflow/` if errors like "pox/openflow exists!" occur.

- **Step 3:** Go into the mininet subdirectory:
```
cd mininet/
sudo python setup.py install
```
3.Compile NS-3

- **Step 1:** Some preparations
```
sudo sh prepinstall.sh
```
- **Step 2:** Configuration 
```
CXXFLAGS="-std=c++0x" ./waf configure --enable-sudo
```
- **Step 3:** Build 
```
sudo ./waf build
sudo ./waf --apiscan=all
sudo ./waf install
```
4.Test
- **Step 1:** Open one terminal(named as T1), in T1 run:
```
sudo sh pre-config.sh
```
- **Step 2:** Open another terminal(named as T2), in T2 run:
```
cd examples/
sudo python one-switch-in-band-controller-csma.py
```
- **Step 3:** in T1 run:
```
sudo sh post-config.sh
```

If there is no error, then everything should be done.


#### Exceptions:
**Error:**
ImportError: libns3.25-core-debug.so: cannot open shared object file: No such file or directory

**Solution:**

- **Step 1:** 
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/sduwn/SDUWN/ns-allinone-3.25/ns-3.25/build
```
- **Step 2:**
```
sudo ldconfig
```


**Error:**
RTNETLINK answers: File exists

**Solution:**

- **Step1:** Before test, run:
```
sudo mn -c
```

Li Wei, Yuxin Tang, Yuching Cao
08/27/2017

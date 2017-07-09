'''
	might need to convert a bunch of the objects into Ptr's
'''
import ns
import ns.core
import ns.network
import ns.mobility
import ns.applications
import ns.internet

import ns.uan
import ns.stats
import ns3
import mininet.log
import sys

def ReceivePacket(socket):
	while True:
		packet = socket.RecV()
		print("Received data: " + packet.GetSize())
	
def runMain(argc, argv):

	ns.core.LogComponentEnable("UanChannel", ns.core.LOG_ALL)
	ns.core.LogComponentEnable("UanHelper", ns.core.LOG_ALL)
	ns.core.LogComponentEnable("UanNetDevice", ns.core.LOG_ALL)
	ns.core.LogComponentEnable("UanPhyGen", ns.core.LOG_ALL)
	ns.core.LogComponentEnable("UanPropModelThorp", ns.core.LOG_ALL)
	ns.core.LogComponentEnable("OnOffApplication", ns.core.LOG_ALL)
	ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_NODE)
	ns.core.LogComponentEnableAll(ns.core.LOG_PREFIX_TIME)

	ns3.GlobalValue.Bind("SimulatorImplementationType", ns3.StringValue("ns3::RealtimeSimulatorImpl"))
	ns3.GlobalValue.Bind ("ChecksumEnabled", ns3.BooleanValue (True));

	nNodes = 100
	sPreadCoef = 1.5
	rxThresh = 5
	txPower = 140
	windspeed = 4.5
	shipcontri = 0.5
	

	''' channel module configurations begin '''
	nodes = ns.network.NodeContainer()
	nodes.Create(nNodes)
	
	uan = ns.uan.UanHelper()
	chan = ns.uan.UanChannel()
	
	# noise configuration
	noise_object=ns.uan.UanNoiseModelDefault()
	noise_ptr = noise_object.GetObject(ns.uan.UanNoiseModelDefault.GetTypeId())
	#noise.SetWind(windspeed)
	#noise.SetShipping(shipcontri)
	#noise.Wind = ns.core.DoubleValue(windspeed)
	#noise.Shipping = ns.core.DoubleValue(shipcontri)
	#noisePtr = ns.core.PointerValue(noise)
	chan.SetNoiseModel(noise_ptr)
	#chan.SetAttribute("NoiseModel", noise_ptr)
	# propagation model configuration
	prop_object=ns.uan.UanPropModelThorp()
	prop_ptr = prop_object.GetObject(ns.uan.UanPropModelThorp.GetTypeId())
	#prop.SpreadCoef = ns.core.DoubleValue(sPreadCoef)
	#prop.SetSpreadCoef(sPreadCoef)
	#propPtr = ns.core.PointerValue(prop)
	chan.SetPropagationModel(prop_ptr)
	#chan.SetAttribute("PropagationModel", prop_ptr)

	# modulation mode configuration
	mode = ns.uan.UanTxMode()
	mode = ns.uan.UanTxModeFactory.CreateMode(ns.uan.UanTxMode.FSK, # modulation type
							   1624, # data rate in BPS: 1152B/5.67s
							   1624,
							   24000,# cetner frequency in Hz
							   6000, # bandwidth in Hz
							   2, 	 # modulation constellation size, 2 for BPSK, 4 for QPSK
							   "Default mode")

	myModes = ns.uan.UanModesList()
	myModes.AppendMode(mode)

	# physical layer channel configuration
	perModel = "ns3::UanPhyPerGenDefault"
	sinrModel = "ns3::UanPhyCalcSinrDefault"
	obf = ns.core.ObjectFactory()
	obf.SetTypeId(perModel)
	per = obf.Create()	# watch
	obf.SetTypeId(sinrModel)
	sinr = obf.Create()
	
	# watch
	uan.SetPhy("ns3::UanPhyGen",
		   "PerModel", ns.core.PointerValue(per),
		   "SinrModel", ns.core.PointerValue(sinr),
		   "SupportedModes", ns.uan.UanModesListValue(myModes),
		   "RxThreshold", ns.core.DoubleValue(rxThresh),
		   "TxPower", ns.core.DoubleValue(txPower))

	# configure MAC module for uan channel
	uan.SetMac("ns3::UanMacAloha")
	
	# install wireless devices onto ghost nodes
	
	#devices = ns.network.NetDeviceContainer(uan.Install(nodes, chan))
	devices = uan.Install(nodes, chan)
	devices = uan.Install(nodes)
	#mobility
	mobility = ns.mobility.MobilityHelper()
	positionAlloc = ns.mobility.ListPositionAllocator()
	
	mDist = 50

	for i in range(0,nNodes):
		positionAlloc.Add(ns.core.Vector((i - nNodes/2) * mDist, 0.0, -10.0))
	mobility.SetPositionAllocator(positionAlloc)
	mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel")
	mobility.Install(nodes)

	mobility.SetPositionAllocator(positionAlloc)
	mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel")
	mobility.Install(nodes)

	''' setup tap bridges from vmuan-2km.cc '''
	tapBridge = ns3.TapBridgeHelper()
	tapBridge.SetAttribute("Mode", ns.core.StringValue("UseLocal"))
	tapBridge.SetAttribute("DeviceName", ns3.StringValue("tap-vNode1"))	
	tapBridge.Install(nodes.Get(0), devices.Get(0))
	
	tapBridge.SetAttribute ("DeviceName", ns3.StringValue ("tap-vNode2"));
  	tapBridge.Install (nodes.Get (1), devices.Get (1));

  	tapBridge.SetAttribute ("DeviceName", ns3.StringValue ("tap-vNode3"));
  	tapBridge.Install (nodes.Get (2), devices.Get (2));

  	tapBridge.SetAttribute ("DeviceName", ns3.StringValue ("tap-vNode4"));
  	tapBridge.Install (nodes.Get (3), devices.Get (3));

  	tapBridge.SetAttribute ("DeviceName", ns3.StringValue ("tap-vNode5"));
  	tapBridge.Install (nodes.Get (4), devices.Get (4));

  	tapBridge.SetAttribute ("DeviceName", ns3.StringValue ("tap-vNode6"));
  	tapBridge.Install (nodes.Get (5), devices.Get (5));

	'''
	pktskth=ns.network.PacketSocketHelper()
	pktskth.Install(nodes)
	appsocket=ns.network.PacketSocketAddress()

	appsocket.SetSingleDevice(devices.Get(nNodes-1).GetIfIndex())
	appsocket.SetPhysicalAddress(devices.Get (nNodes-1).GetAddress())
	appsocket.SetProtocol(0)
	
	app=ns.applications.OnOffHelper("ns3::PacketSocketFactory",appsocket.GetPhysicalAddress())
	app.SetAttribute("OnTime",ns.core.StringValue("ns3::ConstantRandomVariable[Constant=1]"))
	app.SetAttribute("OffTime",ns.core.StringValue("ns3::ConstantRandomVariable[Constant=0]"))
	app.SetAttribute("DataRate",ns.network.DataRateValue(ns.network.DataRate(1300)))
	app.SetAttribute("PacketSize",ns.core.UintegerValue(1000))
	apps=ns.network.ApplicationContainer(app.Install(nodes.Get(0)))

	sinkNode=nodes.Get(nNodes-1)
    #Ptr<Node> sinkNode = nodes.Get (nNodes-1);
  	psfid = ns3.TypeId.LookupByName("ns3::PacketSocketFactory")
  	sinkSocket = ns3.Socket.CreateSocket(sinkNode, psfid)
  	sinkSocket.Bind (appsocket)
  	#sinkSocket.SetRecvCallback(ns.core.MakeCallback(ReceivePacket));

  	apps.Start(ns.core.Seconds(0.5))
	apps.Stop(ns.core.Seconds(100.5))
	'''

	#NS_LOG_INFO ("Run Simulation.");
  	# ns3.Simulator.Stop(ns.core.Seconds(100.))
  	ns3.Simulator.Run()
  	ns3.Simulator.Destroy()

if __name__ == "__main__":
	ascii = ns3.ofstream("uan-thorp.tr")
	runMain(len(sys.argv), sys.argv)

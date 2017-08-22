import socket
import time
stringSend=""
def string_1k_gen():
	global stringSend
	for i in range(0,1024):
		stringSend = stringSend + 'c'

port=8081
host='10.0.0.1'
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
for i in range(0,100):
	time.sleep(1)
	string_1k_gen()
	s.sendto(stringSend,(host,port))
	stringSend=""
	print i

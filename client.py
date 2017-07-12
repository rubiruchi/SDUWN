import socket
port=8081
host='192.168.123.1'
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.sendto(b'hello,this is a test info !',(host,port))

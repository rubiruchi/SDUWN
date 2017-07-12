# -*- coding: utf-8 -*-
import socket,traceback
host = ''
port = 12345
s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
s.setsockopt(socket.SOL_SOCKET,socket.SO_BROADCAST,1)
s.bind((host,port))
print "Listen on the port 12345......"
while True:
    try:
        sock,addr = s.recvfrom(8192)
        print "Receive data from:",addr
        s.sendto("I'm here BOSS!",addr)
    except (KeyboardInterrupt,SystemExit):
        raise
    except:
        traceback.print_exc()
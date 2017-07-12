import socket
port=8081
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(('192.168.123.1',port))
print('waiting...')
while True:
    data,addr=s.recvfrom(1024)
    print('Received:',data,'from',addr)

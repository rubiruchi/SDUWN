import socket
port=8081
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(('10.0.0.1',port))
print('waiting...')
i=0
while True:
    data,addr=s.recvfrom(1024)
    print('Received:',data,'from',addr)
    i = i+1
    print i

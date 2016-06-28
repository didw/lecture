import socket
dataSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
dataSock.connect( ('127.0.0.1', 4500) )
print("server connected")
for n in range(0,3):
    indata = 'input data : {}'.format(n)
    dataSock.send(bytes(indata, 'utf-8'))
    rdata = dataSock.recv(100)
    print("recv:", str(rdata, 'utf-8'))

dataSock.close()
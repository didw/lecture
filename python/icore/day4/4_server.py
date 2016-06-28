import socket
svrSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
svrSock.bind( ("", 4500) )
svrSock.listen(5)
print("client connect wait..")
dataSock, addr = svrSock.accept()  # hang...
print("client connected from ", addr)

while True:
    try:
        rdata = dataSock.recv(100)
        if not rdata:
            break
        print("recv:", str(rdata, 'utf-8'))
        dataSock.send(rdata)
    except Exception as err:
        print("err", err)
        dataSock.close()
        break

print("Program end")
    

import socket
import pickle

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
        myDic = pickle.loads(rdata)
        print("name:{}, age:{}".format(myDic['name'], myDic['age']))
        dataSock.send(rdata)
    except Exception as err:
        print("err", err)
        dataSock.close()
        break

print("Program end")
    

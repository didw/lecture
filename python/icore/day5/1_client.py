import socket
import pickle

dataSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
dataSock.connect( ('127.0.0.1', 4500) )
print("server connected")

myDic = {"name":"Hong", "age":20}
for n in range(0,3):
    myDic['age'] = 10*n + 20
    dataSock.send( pickle.dumps(myDic) )
    rdata = dataSock.recv(100)
    print("recv:", pickle.loads(rdata))

dataSock.close()
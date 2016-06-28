import asyncore
import socket

class EchoHandler(asyncore.dispatcher_with_send):
    def __init__(self, conn, addr):
        asyncore.dispatcher_with_send.__init__(self, conn)
        print( 'new user from %s' % repr(addr) )
        self.conn = conn
        self.addr = addr

    def handle_read(self):
        data = self.recv(1024)
        if data:
            print("rcv data:",  str( data,'utf-8 ') )
            self.send(data)
    
    def handle_close(self):
        print("client connect close")
        self.close()

class EchoServer(asyncore.dispatcher):
    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.set_reuse_addr()
        self.bind((host, port))
        self.listen(5)
 
    def handle_accept(self):
        sock, addr = self.accept()
        print( 'Incoming connection from' ,addr )
        EchoHandler(sock, addr)

server = EchoServer('', 5600)
asyncore.loop()

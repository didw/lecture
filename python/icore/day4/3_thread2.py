import time
from threading import Thread, Lock

g_n = 0
lock = Lock()

class MyThread(Thread):
    def run(self):
        fn1()
    
def fn1():
    global g_n
    for n in range(1,6):
        print('fn1 called')
        lock.acquire()
        g_n += n
        lock.release()
        time.sleep(1)

def fn2():
    global g_n
    for n in range(6,11):
        print('fn2 called')
        lock.acquire()
        g_n += n
        lock.release()
        time.sleep(1)

if __name__ == '__main__':
    th1 = MyThread()
    th1.start()
    fn2()
    print(g_n)

import time
from threading import Thread

class MyThread(Thread):
    def run(self):
        hello()


def hello():
    str_seq = ["aaa", "bbb", "ccc"]
    for i in range(10):
        print("Hello", str_seq[i%3])
        time.sleep(1)

def foo(n):
    while True:
        print("foo", n)
        time.sleep(1)


if __name__ == '__main__':
    th1 = MyThread()
    th1.start()
    th1.join(5)
    while True:
        print("main..")
        time.sleep(1)

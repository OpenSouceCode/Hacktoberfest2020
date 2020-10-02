from time import sleep
from threading import Thread

class Hello(Thread):
    def run():
    for i in ramge(5):
        print("Hello")
        sleep(1)
        
class Hi(Thread)
    def run():
    for i in range(5):
    print("Hi")
    sleep(1)
    
hello = Hello()
hi = Hi()

hello.start()
sleep(0.2)
hi.start()

hello.join()
hi.join()

print("Bye")
print("Bye2")

# MULTI THREADING WITHOUT USING CLASSES

def hello():
    for i in range(5):
        Print("Hello")
        
def hi():
    for i in range(5):
        print("Hi")
        
t1 = Thread(target= hello)
t2 = Thread(target= hi)

t1.start()
t2.start()

t1.join()
t2.join()
print("Bye")

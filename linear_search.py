import time
def searching(a,n,search):
    for i in range(n):
        if a[i]==search:
            return i
    return -1

n=int(input("Enter no. of elements="))
a=[None]*n
for i in range(n):
    a[i]=int(input("enter element="))
search=int(input("element to be searched="))
seconds1=time.time()
pos=searching(a,n,search)
if pos==-1:
    print("element not found")
else:
    print("element present at",pos+1)
print("function execution time:",(time.time()-seconds1))

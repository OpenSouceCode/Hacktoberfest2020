arr = []
n = int(input("enter size="))
for i in range(n):
    x = int(input("enter value="))
    arr.append(x)
for i in range(n-1):
    for j in range(n-1-i):
        if arr[j] > arr[j+1]:
            arr[j], arr[j+1] = arr[j+1], arr[j]
print(arr)

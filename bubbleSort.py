def bubbleSort(arr): 
	n = len(arr) 

	for i in range(n): 

		for j in range(0, n-i-1): 

			if arr[j] > arr[j+1] : 
				arr[j], arr[j+1] = arr[j+1], arr[j] 

print("Enter array: ", end="")
arr = list(map(int, input().split()))

bubbleSort(arr) 

print ("Sorted array is:") 
for i in arr: 
	print(i, end=" ")

print()

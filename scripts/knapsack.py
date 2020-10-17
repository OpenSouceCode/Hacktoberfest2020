weights=[1,3,6,7,10]
values=[2,4,7,9,12]
n=5
w=10
def knapsack(weights,values,w,n):
	if n==0 or w == 0:
		return 0
	if weights[n-1]<w:
		return max((values[n-1]+ knapsack(weights,values,w-w[n-1],n-1)),(knapsack(weights,values,w,n-1)))
	else:
		return knapsack(weights,values,w,n-1)


result = knapsack(weights,values,w,n)
print(result)

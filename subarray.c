#include<stdio.h>
#define MAX 100
void main()
{
	int arr[MAX], n, k;
	int i = 0, j = 0, x = 0;
	int temp[MAX];
	int min=0, max=0, sum = 0, total_sum = 0;
	printf("Enter the number of elements in the array:");
	scanf_s("%d", &n);
	printf("\nEnter the elements of the array:");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("\nEnter the size of subarray(should be <= n):");
	scanf_s("%d", &k);
	max = temp[0];
	min = temp[0];
	for (int i = 0; i < n - k + 1; i++)
	{
		for (int j = 0; j < k; j++)
		{
			temp[j] = arr[i + j];
			//printf("%d\t", temp[j]); 
			//for checking is the sub array is proper
			if (i == 0)
			{
				max = temp[0];
				min = temp[0];
			}
			
		}
		//printf("\n");
		for (x = 0; x < k; x++)
		{
			if (temp[x] > max)
			{
				max = temp[x];
			}


			if (temp[x] < min)
			{
				min = temp[x];
			}
		}
		sum = min + max;
		total_sum = total_sum + sum;
		max = temp[0];
		min = temp[0];
		sum = 0;
		//printf("\n");
	
	}
	printf("\nSum:%d", total_sum);
}

// 2 5 -1 7 -3 -1 -2
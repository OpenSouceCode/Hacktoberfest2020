#include <stdio.h>
int main()
{
	int A[10],B[10],C[20],m,n,k,i,j;
	printf("Enter the size of first array\n");
	scanf("%d",&m);
	printf("Enter the element\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Enter the size of second array\n");
	scanf("%d",&n);
	printf("Enter the element\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&B[i]);
	}
	i=0;
	j=0;
	k=0;
	while(i<m && j<n)
	{
		if(A[i]<=B[j])
		{
			C[k]=A[i];
			k++;
			i++;
		}
		else
		{
			C[k]=B[j];
			k++;
			j++;
		}
	}
	while(i<m)
	{
		C[k]=A[i];
		k++;
		i++;
	}
	while(j<n)
	{
		C[k]=B[j];
		k++;
		j++;
	}
	printf("After merging\n");
	for(i=0;i<k;i++)
	{
		printf("%d\t",C[i]);
	}
	return 0;
}

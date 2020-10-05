/*this program is to calculate the number of combination using value of n and r*/ 
#include<stdio.h>
#include<conio.h>

int fact(int k); //function to find factorial
main()
{
	int n,r,ans;
	printf("enter value of n\t");
	scanf("%d",&n);
	printf("enter value of r\t");
	scanf("%d",&r);
	ans=fact(n)/(fact(n-r)*fact(r));
	printf("%d",ans);//this gives number of combination of n distinct objects, taken r at a time
	
	
}
int fact(int k)
{
	int i,a=1;
	for(i=1;i<=k;i++)
	{
		a=a*i;
	}
	return a;
}

#include<iostream>
using namespace std;

int main()
{
	//Declarations
	int n; 
	long long int a[100], temp=0;
	int i=0, j=0, count=0;
	
	//cout<<"\nEnter size of array: \n";
	cin>>n;
	
	//cout<<"\nEnter Elements in array: \n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	//Sorting
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(a[n-1] == a[i])
			count++;
	}	
	
	cout<<count;
}

#include<bits/stdc++.h>
using namespace std;
int kth(int a[],int b[],int n,int m,int k)
{
	int i=0,j=0,c=0;
	while(i<n && j<m){
		c++;
		if(a[i]<=b[j]){

			if(c==k){
				return a[i];
			}
						
		   i++;
		}else{
			if(c==k){
				return b[j];
			}
			j++;
		}
	}
	while(i!=n){
		c++;
		if(c==k)return a[i];
		i++;
	}
	while(j!=m){
		c++;
		if(c==k)return b[j];
		j++;
	}
	return -1;
}
int updated_kth(int a[],int b[],int n,int m,int k)
{
	if(n>m){
		return updated_kth(b,a,m,n,k);
	}
	if(n==0 && m>0){
		return b[k-1];
	}
	if(k==1)
	{
		return min(a[0],b[0]);
	}
	int i = min(n,k/2);
	int j = min(m,k/2);
	if(a[i-1]<b[j-1]){
		return updated_kth(a+i,b,n-i,j,k-i);
	}else{
		return updated_kth(a,b+j,i,m-j,k-j);
	}
}
int main()
{
    int arr1[5] = {2, 3, 6, 7, 9}; 
    int arr2[4] = {1, 4, 8, 10}; 
    int k = 5; 
    cout << updated_kth(arr1, arr2, 5, 4, k); 
    return 0;
}

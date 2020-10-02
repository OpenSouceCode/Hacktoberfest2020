#include<bits/stdc++.h>
using namespace std;
int findMaximum(int a[],int l,int r)
{
   if(l>r)return -1;
   if(l==r)return a[l];
   int m = l+(r-l)/2;
   if(a[m]>a[m+1]){
   	return findMaximum(a,l,m);
   }	else{
   	return findMaximum(a,m+1,r);
   }
}
int main()  
{  
    int arr[] = {1, 3, 50, 10, 9, 7, 6};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    cout << "The maximum element is " << findMaximum(arr, 0, n-1);  
    return 0;  
}  


#include <climits> 
#include <iostream> 
using namespace std; 
bool possible(int a[],int ans,int n,int k)
{
	int st=1,cur=0;
	for(int i=0;i<n;i++){
		if(cur+a[i]>ans){
			st++;if(st>k)return false;
			cur=a[i];
		}else{
			
	cur+=a[i];	
		}

	}
	return true;
}
int partition(int a[],int n,int k)
{
	int l=INT_MAX,r=0,ans;
	for(int i=0;i<n;i++){
		r+=a[i];
		l=min(l,a[i]);
	}
	while(l<=r){
		int m=l+(r-l)/2;
		if(possible(a,m,n,k)){
			ans=m;
			r=m-1;
		}else{
			l=m+1;
		}
	}
return ans;	
}
int main() 
{ 
	int arr[] = { 10, 20, 60, 50, 30, 40 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	cout << partition(arr, n, k) << endl; 

	return 0; 
} 


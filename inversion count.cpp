#include<bits/stdc++.h>
using namespace std;
#define ll long long
int merge(int arr[],int l,int m,int r,int temp[]){
	int i=l,j=m,k=l;
	int ans=0;
	while((i<=(m-1)) && (j<=r) ){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}else{
			temp[k++]=arr[j++];
			ans+=(m-i);
		}
	}
	while(i<=(m-1)){
		temp[k++]=arr[i++];
	}
	while(j<=r){
		temp[k++]=arr[j++];
	}
	for(int i=l;i<=r;i++){
		arr[i]=temp[i];
	}
	return ans;
}
int mergeSortutil(int arr[],int l,int r,int temp[]){
	if(l<r){
		int m=l+(r-l)/2;
		int ans=0;
		ans+=mergeSortutil(arr,l,m,temp);
		ans+=mergeSortutil(arr,m+1,r,temp);
		ans+=merge(arr,l,m+1,r,temp);
		return ans;
	}else{
		return 0;
	}
}
int mergeSort(int arr[],int n){
	//if(n==0)return 0;
	int temp[n];
	return mergeSortutil(arr,0,n-1,temp);
}
int main() 
{ 
    int arr[] = { 1, 20, 6, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int ans = mergeSort(arr, n); 
    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
	}
	cout<<"\n";
    cout << " Number of inversions are " << ans; 
    return 0; 
} 


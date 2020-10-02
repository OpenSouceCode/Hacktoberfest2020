#include<bits/stdc++.h>
using namespace std;
int search(int a[],int l,int r)
{
	if(l>r)return -1;
	if(l==r)return a[l];
	int m=l+(r-l)/2;;
	if(m%2==0){
		if(a[m]==a[m+1]){
			return search(a,m+2,r);
		}else{
			return search(a,l,m);
		}
	}else{
		if(a[m]==a[m-1]){
			return search(a,m+1,r);
		}else{
			return search(a,l,m-1);
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[] = {1, 1, 2, 4, 4, 5, 5, 6, 6}; 
    int len = sizeof(arr)/sizeof(arr[0]); 
    cout<<search(arr, 0, len-1); 
    return 0;

}

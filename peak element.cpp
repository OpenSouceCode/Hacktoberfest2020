#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define for(i,n) for(ll i=0;i<n;i++)
void find_peak(ll a[],ll n,ll l,ll r)
{
	if(l>=r)return;


		ll m=l+(r-l)/2;
		if(m==0){
			if(a[m]>=a[m+1]){
				cout<<a[m]<<"\n";
			}
		}else if(m==(n-1)){
				if(a[m]>=a[m-1]){
					cout<<a[m]<<"\n";
				}
		}
		else{
				if(a[m]>=a[m-1] and a[m]>=a[m+1]){
					cout<<a[m]<<"\n";
				}
			}
	find_peak(a,n,l,m-1);
	find_peak(a,n,m+1,r);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n=7;
	ll a[n]={10,20,15,2,23,90,67};
	find_peak(a,n,0,n-1);
	return 0;
}

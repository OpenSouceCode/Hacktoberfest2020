#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define for(i,n) for(ll i=0;i<n;i++) 

int main()
{
	ll n=7;
	ll a[n]={1,2,3,3,3,3,4};
	ll cnt = upper_bound(a,a+n,4)-lower_bound(a,a+n,4);
	if(cnt>(n/2)){
		cout<<"yes"<<"\n";
	}else{
		cout<<"no"<<"\n";
	}
	return 0;
}

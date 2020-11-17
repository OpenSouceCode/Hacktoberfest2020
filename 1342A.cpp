#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;cin>>t;
	while(t--){
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		int ans = 0;
		if(b<2*a){
			int l = abs(x-y);
			ans = min(x,y)*b + a*l;
		}
		else ans = (x+y)*a;
		cout<<ans<<endl;
	}
}
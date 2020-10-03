#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frn(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define test int t;cin>>t; while(t--)
#define mp make_pair
#define pb push_back
#define pu push
#define fi first
#define se second
#define mod 1000000007
void fast() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
bool myc(int a,int b) {
	return a>b;
}

int32_t main() {
	fast();
	test{
		string s;
		cin>>s;
		int n = s.length();
		int ones = 0;
		int zeros = 0;
		fr(i,0,n) if(s[i] == '0') zeros++; else ones++;
		int e = min(zeros,ones);
		if(e%2 == 1) cout<<"DA"<<endl;
		else cout<<"NET"<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define mo 1000000007
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> seti;
void fast() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
struct line {
    int m, b;
    // y = mx + b
};
long double intersectX ( line X, line Y ) {
    // X.m * x + X.b = Y.m * x + Y.b
    // x = (Y.b-X.b)/(X.m-Y.m);
    if ( X.m == Y.m )
        return 1e17;
    else
        return (double)(Y.b - X.b) / (double)(X.m - Y.m);
}
int eval (
    int x , line X ) {
    return ((X.m) * x + X.b);
}
deque < line > st;
vector < long double > points;
void addline ( line X ) {
    if ( st.empty() ) {
        st.pb(X);
        return;
    }
    if ( st.size() == 1 ) {
        points.pb(intersectX(X, st.back()));
        st.pb(X);
        return;
    }
    while ( points.size() ) {
        // l1 -> l2 -> X
        // if intersection of l1 and X lies before the intersection of
        // l2 and l1 then l2 is a useless line so we remove it
        line l2 = st.back();
        st.pop_back();
        line l1 = st.back();
        if ( intersectX(X, l1) > points.back() ) {
            st.push_back(l2);
            break;
        }
        else {
            points.pop_back();
        }
    }
    points.pb(intersectX(X, st.back()));
    st.pb(X);
}
int findbest (int x ) {
    int idx = lower_bound(points.begin(), points.end(), x) - points.begin();
    return eval(x, st[idx]);
}


int32_t main () {
    fast();
   
        int n;
        cin>>n;
        int a[n+1];
        int dp[100005];
        memset(dp,0,sizeof dp);
        set<int> s4;
        set<int> s6;
        set<int> s2;
        set<int> s8;
        fr(i,0,n){
            cin>>a[i];
            dp[a[i]]++;
            if(dp[a[i]]>=2) s2.insert(a[i]);
            if(dp[a[i]]>=4) s4.insert(a[i]);
            if(dp[a[i]]>=6) s6.insert(a[i]); 
            if(dp[a[i]]>=8) s8.insert(a[i]);
        }
        int q;
        cin>>q;
        fr(i,0,q){
            char l;
            cin>>l;
            int d;
            cin>>d;
            if(l=='+'){
                dp[d]++;
                 if(dp[d]>=2) s2.insert(d);
                 if(dp[d]>=4) s4.insert(d);
                 if(dp[d]>=6) s6.insert(d); 
                 if(dp[d]>=8) s8.insert(d);
            }
            else{
                 dp[d]--;
                 if(dp[d]<2) s2.erase(d);
                 if(dp[d]<4) s4.erase(d);
                 if(dp[d]<6) s6.erase(d); 
                 if(dp[d]<8) s8.erase(d);
            }
            if(s8.size()>=1 || ((s6.size()>=1)&&(s2.size()>1))||(s4.size()>1)||(s4.size()&&(s2.size()>2))) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    return 0;
}
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
        int pre[n+1];
        cin>>a[0];
        if(n==1){
            cout<<a[0];
            return 0;
        }
        pre[0] = ~a[0];
       // cout<<pre[0]<<endl;
        fr(i,1,n){
            cin>>a[i];

            pre[i] = pre[i-1]&(~a[i]);
            //cout<<pre[i]<<endl;
        }
        int suf[n+1];
        suf[n-1] = ~a[n-1];
        fr(i,1,n){
            suf[n-i-1] = suf[n-i]&(~a[n-i-1]);
        }
        pii ans;
        ans.fi = INT_MIN;
        int e = 0;
        e = ~e;
        //cout<<endl;
        //cout<<e<<endl;
        fr(i,1,n-1){
            //cout<<ans.fi<<endl;
            if( ((pre[i-1]&suf[i+1])&a[i]) > ans.fi){
                ans.fi = (pre[i-1]&suf[i+1]&a[i]);
                ans.se = i;
            }
        }
        if( (pre[n-2]&(a[n-1]&(e))) > ans.fi){
            ans.fi = pre[n-2]&a[n-1]&e;
            ans.se = n-1;
        }
        if( (suf[1]&(a[0]&(e))) > ans.fi) ans.se = 0;
        cout<<a[ans.se]<<" ";
        fr(i,0,n) if(i!=ans.se) cout<<a[i]<<" ";
       // cout<<endl;
    
    return 0;
}
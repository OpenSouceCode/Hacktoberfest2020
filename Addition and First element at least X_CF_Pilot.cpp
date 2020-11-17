#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
/*
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> seti;*/
void fast() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int tree[400004];
int lazy[400004];

void update(int s,int e,int qs,int qe,int i,int up){
  if(lazy[i]){
    tree[i]+=lazy[i];
    if(s!=e){
      lazy[2*i] += lazy[i];
      lazy[2*i+1] += lazy[i];
    }
    lazy[i] = 0;
  }
  if(qs<=s && qe>=e){
    tree[i]+=up;
    if(s!=e){
      lazy[2*i] += up;
      lazy[2*i+1] += up;
    }
    return;
  }
  if(s>qe || e<qs) return;
  update(s,(s+e)/2,qs,qe,2*i,up);
  update((s+e)/2+1,e,qs,qe,2*i+1,up);
  tree[i] = max(tree[2*i],tree[2*i+1]);
}
int query(int s,int e,int m,int x,int i){
  if(lazy[i]){
    tree[i]+=lazy[i];
    if(s!=e){
      lazy[2*i] += lazy[i];
      lazy[2*i+1] += lazy[i];
    }
    lazy[i] = 0;
  }
//  cout<<m<<" "<<e<<" "<<tree[i]<<endl;
  if(m>e) return -1;
  if(tree[i]>=x){
    if(s==e) return s;
    int l = query(s,(s+e)/2,m,x,2*i);
    if(l==-1) return query((s+e)/2+1,e,m,x,2*i+1);;
    return l;
  }
  return -1;
}

int32_t main() {
  fast();
  memset(tree,0,sizeof tree);
  memset(lazy,0,sizeof lazy);
  int n,m;
  cin>>n>>m;
  int a,b,c,d;
  fr(i,0,m){
    cin>>a;
    if(a==1){
      cin>>b>>c>>d;
      update(0,n-1,b,c-1,1,d);
      //cout<<query(0,n-1,b,1)<<endl;
    }
    else{
      cin>>b>>c;
      cout<<query(0,n-1,c,b,1)<<endl;
    }
  }
  return 0;
}

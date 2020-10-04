#include<bits/stdc++.h>
using namespace std;
 
int main(){
     long long int a=1,d,n,m;
     cin>>n>>m;
     d=n*(n+1)/2;
     m=m%d;
     while(a<=m)
     {
          m=m-a;
          a++;
     }
     cout<<m;
     return 0;
}

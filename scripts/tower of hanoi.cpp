#include<bits/stdc++.h>
using namespace std;
void tower(int n,char beg,char aux,char end)
{
    if(n==1)
    {
        cout<<beg<<"-->"<<end<<endl;
        return;
    }
    tower(n-1,beg,end,aux);
    cout<<beg<<"-->"<<end<<endl;
    tower(n-1,aux,beg,end);
}
main()
{
    int n;
    cin>>n;
    tower(n,'a','b','c');
}

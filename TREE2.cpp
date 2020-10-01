#include<bits/stdc++.h>
using namespace std ;
bool isZero(long long int k){
    return (k == 0);
}

void solution ( long long int n ){
    long long int a[n] , i , count = 0 ;
    for ( i = 0 ; i < n ; i++ )
        cin >> a[i] ;
    sort ( a , a + n );
    unordered_set<long long int> s; 
    for (int i=0; i<n; i++) 
    {
        if (s.find(a[i])==s.end() && a[i] != 0 ) 
        { 
            s.insert(a[i]);
            count++ ; 
        } 
    } 
    cout << count << endl ;
} 

int main () {
    long long int n ,t ;
    cin >> t ;
    while ( t-- ){
        cin >> n ;
        solution (n);
    }
}
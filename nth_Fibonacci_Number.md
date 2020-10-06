#include<iostream>
using namespace std;


int main(){

    int n;
    cin >> n ;
    int a=1,b=1,sum=0;
    for (int term=3;term<=n;term++){
        sum=a+b;
        a=b;
        b=sum;
    }
    cout << sum ;
    
}

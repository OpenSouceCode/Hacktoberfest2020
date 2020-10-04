#include <iostream>
using namespace std;
void check_prime(int n){
    bool flag=0;
    for(int i=2;i<=n/2;i++){
        flag=0;
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag==1)
    cout<<"not prime"<<endl;
    else
    cout<<"prime"<<endl;
    
    }
int main(){
    int n,t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        check_prime(n);
    }
    return 0;
}

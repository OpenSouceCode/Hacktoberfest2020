#include <iostream>
using namespace std;
int fastPower(int a,int n){
    if(n==0){
        return 1;
    }
    int small = fastPower(a,n/2);
    small *= small;
    if(n&1){
        return a* small;
        }
    else{
        return small;
    }
}

int main() {
	int a,b;
	cin>>a>>b;
	cout<<fastPower(a,b);
	return 0;
}

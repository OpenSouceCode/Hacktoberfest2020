// Prints all primes between 1 to n.
// Runtime complexity : O(N log (log N))
// Space complexity: O(N)

# include <bits/stdc++.h>

using namespace std;

void Primes(int n) {
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    
    for(int p=2; p*p<=n; p++) {
        if(prime[p] == true){
            for(int i = p*p; i<=n; i+=p){
                prime[i] = false;
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(prime[i]){
            cout << i << " ";
        }
    }
}

int main(){
    int t;
    int n;
    cin >> t;
    while(t--) {
        cin >> n;
        Primes(n);
        cout << endl;
    }
    return 0;
    
}
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
bool prime(ll n){
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}        
int main() {
    KHALED_WALEED_ATTIA
    int t;
    cin >>t;
    while(t--){
        ll n;
        cin >>n;
        /*
            n -> prime => impossible
            n -> not prime => 1 a b    a*b = n 
        */
       bool done = 0;
       for(ll i = 2; i*i <= n; i++){
            if(n%i == 0 && i!=n/i){   
                cout<<1<<space<<i<<space<<n/i<<endl;
                done = 1;
                break;
            }
        }
        if(!done)
            cout<<-1<<endl;
    }
    return 0;
}
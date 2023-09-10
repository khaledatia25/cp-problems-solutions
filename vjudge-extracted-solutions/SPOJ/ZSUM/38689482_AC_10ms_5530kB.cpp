/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 10000007
using namespace std;


/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
ll modular_expo(ll base, ll power, ll mod){
    ll res = 1;
    while(power>0){
        if(power&1)
            res = ( (res%mod) * (base%mod) )%mod;
        base = ((base%mod)*(base%mod))%mod;
        power >>=1; 
    }
    return res%mod;
}
ll n,k;
void solve(){
    cout<<(modular_expo(n,k,MOD)+modular_expo(n,n,MOD)+2*modular_expo(n-1,k,MOD)+2*modular_expo(n-1,n-1,MOD))%MOD<<"\n";
}
int main() {
    FIO;
    int t = 1;
    while(cin >>n >>k){
        if(n == 0&&k==0)break;
        solve();
    }
    return 0;
}



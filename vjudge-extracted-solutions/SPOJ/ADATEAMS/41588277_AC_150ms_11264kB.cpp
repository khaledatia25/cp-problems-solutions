#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
void fileInput();
const int N = 1000000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
const ll mod = 1000000007;


ll fact[N];
void calcF(){
    fact[0] = 1;
    for(ll i = 1; i < N; i++){
        fact[i] = (fact[i-1]%mod * i%mod)%mod;
    }
}
ll modular_expo(ll x, ll n, ll m){
    ll res = 1;
    while(n>0)
    {
        if(n%2==1)
            res = ( ( res % m ) * ( x % m ) ) % m;
        x = ( ( x % m ) * ( x % m ) ) % m;
        n = n / 2;
    }
    return res%m;
}


ll mod_inverse(ll a){
    return modular_expo(a, mod-2LL, mod);
}
ll nCr(ll n, ll r){
    return (fact[n]%mod * mod_inverse(fact[n-r])%mod * mod_inverse(fact[r])%mod)%mod;
}
int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    calcF();
    /*
     mod mod mod mod mod mod mod mod mod mod mod mod mod mod mod mod mod mod mod
     */
    ll n, a, b, d;
    while(cin >>n >>a >>b >>d){
        ll ans = modular_expo(nCr(b, d), a, mod);
        ans = ans%mod * nCr(n, a)%mod;
        cout<<ans%mod<<endl;
    }
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
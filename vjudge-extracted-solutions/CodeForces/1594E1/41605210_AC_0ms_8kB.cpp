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


ll nCr(ll n, ll r){
    if(n<r)
        return 0;
    ll ans = 1;
    ll d = 1, rem; // r!
    r = max(r, n-r);
    for (ll i = r + 1; i <= n; i++){
        rem = ans % d;
        ans = ans / d * i + rem * i /d;
        d++;
    }
    return ans;
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

int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    ll k;
    cin >>k;
    /*
        ans = 6 * (4)^(2^k - 2)
    */
    ll ans = (6 * modular_expo(4, (1LL<<k) - 2, mod))%mod;
    cout<<ans<<endl;
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
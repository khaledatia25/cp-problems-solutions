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
const int mod = 1000000000;

ll nCr(ll n, ll r){
    ll ans = 1;
    ll d = 1; // r!
    r=max(r, n-r);
    for (ll i = r + 1; i <= n; i++){
        ans = ans * i;
        ans /= d;
        d++;
    }
    return ans;
}

int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    ll n, m, t;
    cin >>n >>m >>t;
    ll ans = 0;
    for(int i = 4; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i+j == t){
                ans += nCr(n, i)* nCr(m, j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
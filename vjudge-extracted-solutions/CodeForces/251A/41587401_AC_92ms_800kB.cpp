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
    ll d = 1, rem; // r!
    r = max(r, n-r);
    for (ll i = r + 1; i <= n; i++){
        rem = ans % d;
        ans = ans / d * i + rem * i /d;
        d++;
    }
    return ans;
}



int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    ll n, d, ans = 0;
    cin >>n >>d;
    vector<ll>v(n);
    for(ll &i : v)
        cin >>i;

    int last = 0;
    for(int i = 0; i < n; i++){
        int j = upper_bound(v.begin(), v.end(), v[i] + d) - v.begin();
        if(j-i>=3){
            ans += nCr(j-i, 3);
            if(last - i >= 3){
                ans -= nCr(last-i, 3);
            }
            last = j;
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
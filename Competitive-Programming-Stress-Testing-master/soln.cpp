/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define space " "
ll func(ll x, ll n, ll m) {
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        ret += min(x / i, m);
    }
    return ret;
}
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll st = 1, en = n * m, ans = -1;
        while (st <= en) {
            ll mid = st + en >> 1;
            if (func(mid, n, m) < k) {
                st = mid + 1;
            } else {
                en = mid - 1;
                ans = mid;
            }
        }
        ll cnt = 0;
        for (ll i = 1; i * i <= ans; i++) {
            if (ans % i == 0) {
                if (i <= n && ans / i <= m) cnt++;
                if (i * i != ans) {
                    if (ans / i <= n && i <= m) cnt++;
                }
            }
        }
        cout << ans << space << cnt << endl;
    }
    return 0;
}

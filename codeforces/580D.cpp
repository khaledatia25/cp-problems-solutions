/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl '\n'

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define prec(n) cout << fixed << setprecision(n)
#define countbits(n) __builtin_popcount(n)

#define ll long long
#define int long long
#define OO (ll)1e18
#define oo (ll)1e9
#define angle(a) (atan2((a).imag(), (a).real()))

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_map = tree<T, map<T, F>, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_multimap = tree<T, map<T, F>, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T>
using max_heap = priority_queue<T>;

using ld = long double;

void fileInput(/*Hello World*/);

typedef complex<double> point;

const int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 },
dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const ll mod = 1e9 + 7;
// const ll mod = 998244353;
// const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 1e4 + 9;

void init() {}

void elmtarshm(int tc) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>s(n);
    for (int i = 0; i < n;i++) {
        cin >> s[i];
    }
    vector<vector<int>>rule(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < k;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        v--;u--;
        rule[u][v] = w;
    }
    vector<vector<int>>dp(1 << n, vector<int>(n + 1, 0));
    for (int i = 0;i < n;i++)dp[(1 << i)][i] = s[i];

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n;i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n;j++) {
                    if (!(mask & (1 << j))) {
                        dp[mask | (1 << j)][j] = max(dp[mask | (1 << j)][j], dp[mask][i] + rule[i][j] + s[j]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (countbits(mask) == m) {
            for (int i = 0; i < n;i++) {
                ans = max(ans, dp[mask][i]);
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
        // handle file input
        fileInput();
    init();
    int t = 1;
    //    cin >> t;
    int tc = 1;
    while (t--) {
        elmtarshm(tc++);
    }

    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
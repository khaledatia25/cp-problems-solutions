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

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll mod = 1e9 + 7;
// const ll mod = 998244353;
// const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 3e3 + 9;
int dp[N][N];
// dp[i][j] is number of ways to put numbers in prefix 'i'
// suxh that the last number is j
void init() {}
void add_self(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}
void elmtarshm(int tc) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[1][1] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= len; i++) {
            add_self(dp[len - 1][i], dp[len - 1][i - 1]);
        }
        for (int num = 1; num <= len; num++) {
            int L, R;
            if (s[len - 2] == '<') {
                L = 1;
                R = num - 1;
            } else {
                L = num;
                R = len - 1;
            }
            add_self(dp[len][num], (mod + dp[len - 1][R] - dp[len - 1][L - 1]) % mod);
                }
    }
    int ans = 0;
    for (int num = 1; num <= n; num++) {
        add_self(ans, dp[n][num]);
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
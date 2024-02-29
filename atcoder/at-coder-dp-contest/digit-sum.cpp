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
const ll N = 1e4 + 9;
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void init() {}
int sol(int num) {
    int dp[61][61][2];
    memset(dp, 0, sizeof dp);
    bitset<61> n(num);
    // dp[i][j][can] number of of good binary representations that can at index i and with j ones till now and we can take ones
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for (int idx = 0; idx <= 60; idx++) {
        for (int can : {0, 1}) {
            for (int j = 0; j < idx; j++) {
                if (can) {
                    for (int digit : {0, 1}) {
                        dp[idx][1][j] += dp[idx + 1][digit][j - digit];
                    }
                } else {
                    dp[idx][0][j] += dp[idx + 1][0][j];
                }
            }
        }
    }
}

void elmtarshm(int tc) {
    int num;
    cin >> num;
    cout << sol(num);
    // int k;
    // string s;
    // cin >> s >> k;
    // int len = s.size();
    // vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(3)));
    // // dp[rem][smaller] number of ways to make a number of with digits sum reminder equal to rem till now
    // dp[0][0][0] = 1;
    // int idx = 0;
    // for (int i = 0; i < len; i++) {
    //     dp[idx ^ 1].assign(k + 1, vector<int>(2, 0));
    //     for (int rem = 0; rem < k; rem++) {
    //         for (int smaller : {0, 1}) {
    //             for (int digit = 0; digit < 10; digit++) {
    //                 if (digit > s[i] - '0' && !smaller) {
    //                     break;
    //                 }
    //                 int& ch = dp[idx ^ 1][(rem + digit) % k][smaller || (digit < s[i] - '0')];
    //                 ch = (ch % mod + dp[idx][rem][smaller] % mod) % mod;
    //             }
    //         }
    //     }
    //     idx ^= 1;
    // }
    // int ans = (dp[idx][0][0] % mod + dp[idx][0][1] % mod) % mod;
    // ans = (ans - 1 + mod) % mod;
    // cout << ans << endl;
}
int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    // fileInput();
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
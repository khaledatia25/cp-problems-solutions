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

int add(int a, int b) {
    return (a % mod + b % mod + mod) % mod;
}
int sub(int a, int b) {
    return (a % mod - b % mod + mod) % mod;
}

void sol1() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &I : v) cin >> I;
    vector<int> dp(k + 1);
    dp[0] = 1;
    // dp[i] number of ways to distribute i candies
    for (int i = 0; i < n; i++) {
        vector<int> partial(k + 1);
        for (int j = k; j >= 0; --j) {
            int L = j + 1;
            int R = j + min(k - j, v[i]);
            if (L <= R) {
                partial[L] = add(partial[L], dp[j]);
                if (R < k) partial[R + 1] = sub(partial[R + 1], dp[j]);
            }
        }
        int sum = 0;
        for (int j = 0; j <= k; j++) {
            sum = add(sum, partial[j]);
            dp[j] = add(sum, dp[j]);
        }
    }
    // for (int i = 0; i <= k; i++) {
    //     cout << dp.get(i, i + 1) << space;
    // }
    // cout << endl;
    cout << dp[k] << endl;
}
void init() {}

void elmtarshm(int tc) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &I : v) cin >> I;
    vector<int> dp(k + 1);
    dp[0] = 1;
    // dp[i] number of ways to distribute i candies
    for (int i = 0; i < n; i++) {
    }
    // for (int i = 0; i <= k; i++) {
    //     cout << dp.get(i, i + 1) << space;
    // }
    // cout << endl;
    cout << dp[k] << endl;
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
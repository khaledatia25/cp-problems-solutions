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
const ll N = 100 + 9;
int dp[2][N][N * N];
void min_self(int &a, int b) {
    a = min(a, b);
}
void init() {}
void elmtarshm(int tc) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt1 = 0, cnt0 = 0;
    for (auto i : s) {
        if (i == '0')
            cnt0++;
        else
            cnt1++;
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N * N; k++) {
                dp[idx ^ 1][j][k] = N;
            }
        }
        for (int j = 0; j <= i; j++) {
            for (int cnt = 0; cnt <= j * (i - j); cnt++) {
                min_self(dp[idx ^ 1][j + 1][cnt], dp[idx][j][cnt] + (s[i] != '0'));
                min_self(dp[idx ^ 1][j][cnt + j], dp[idx][j][cnt] + (s[i] != '1'));
            }
        }
        idx ^= 1;
    }

    int need = cnt1 * cnt0 / 2;
    cout << dp[idx][cnt0][need] / 2 << endl;
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
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
const ll N = 2e5 + 9;

vector<int> DP;
int SZ;
void update(int i, int val, int x, int lx, int rx) {
    if (rx - lx == 1) {
        DP[x] = val;
        return;
    }
    int m = lx + rx >> 1;
    if (i < m) {
        update(i, val, 2 * x + 1, lx, m);
    } else {
        update(i, val, 2 * x + 2, m, rx);
    }
    DP[x] = max(DP[2 * x + 1], DP[2 * x + 2]);
}

void update(int i, int val) {
    update(i, val, 0, 0, SZ);
}

int get(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) {
        return 0;
    }
    if (lx >= l && rx <= r) {
        return DP[x];
    }
    int m = lx + rx >> 1;
    int L = get(l, r, 2 * x + 1, lx, m);
    int R = get(l, r, 2 * x + 2, m, rx);
    return max(L, R);
}

int get(int l, int r) {
    return get(l, r, 0, 0, SZ);
}
void set_size(int n) {
    SZ = n + 5;
    while (countbits(SZ) != 1) {
        ++SZ;
    }
    DP.assign(2 * SZ, 0);
}

void init() {}

void elmtarshm(int tc) {
    int n;
    cin >> n;
    set_size(n);
    vector<int> h(n), a(n);
    for (int &I : h) cin >> I;
    for (int &I : a) cin >> I;
    vector<int> dp(n + 1);
    // dp[i] is the maximum beauty till now if the last height is i
    /*
    This takes O(n)
    for (int f = 0; f < n; f++) {
        this take O(n)
        for (int height = 0; height < h[f]; height++) {
            dp[h[f]] = max(dp[h[f]], dp[height] + a[f]);
        }
    }
    total O(n^2)
    optimaize the inner loop with segment tree
    */
    for (int f = 0; f < n; f++) {
        int temp = get(0, h[f] + 1);
        update(h[f], temp + a[f]);
    }
    cout << DP[0] << endl;
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
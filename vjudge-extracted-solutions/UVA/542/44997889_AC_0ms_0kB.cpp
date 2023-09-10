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

template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class F>
using ordered_map = tree<T, map<T, F>, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class F>
using ordered_multimap = tree<T, map<T, F>, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template<class T>
using max_heap = priority_queue<T>;

using ld = long double;

void fileInput(/*Hello World*/);

typedef complex<double> point;

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
        dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
//const ll mod = 1e9 + 7;
//const ll mod = 998244353;
//const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 1e4 + 9;
int prob[16][16];
int n = 16;
vector<string> teams;
double dp[16];

void rec(int l = 0, int r = 15) {
    if (r == l) {
        dp[l] = 1.0;
        return;
    }
    int mid = l + r >> 1;
    rec(l, mid);
    rec(mid + 1, r);
    double temp[16];
    for (int i = l; i <= r; i++) {
        double c = 0;
        for (int j = (i <= mid ? mid + 1 : l); j <= (i <= mid ? r : mid); j++) {
            if (i != j) {
                c += dp[j] * 1.0 * prob[i][j] / 100.0;
            }
        }
        temp[i] = dp[i] * c;
    }
    for (int i = l; i <= r; i++) {
        dp[i] = temp[i];
    }
}


void init() {
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
}

void elmtarshm(int tc) {
    teams.resize(16);
    for (auto &I: teams) {
        cin >> I;
        while (I.size() <= 10)I += ' ';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> prob[i][j];
        }
    }
    rec();
    prec(2);
    for (int i = 0; i < n; i++) {
        cout << teams[i] << "p=" << dp[i] * 100.0 << "%" << endl;
    }
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
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
const ll N = 5e2 + 9;

void init() {}
char grid[N][N];
int n, m;
bool check_valid() {
    // check columns
    for (int i = 0; i < n;i++) {
        int cnt_dots = 0;
        for (int j = 0; j < m;j++) {
            if (grid[i][j] == '.')cnt_dots++;
        }
        if ((m - cnt_dots) % 2 == 1) {
            return false;
        }
    }
    // check rows
    for (int j = 0; j < m;j++) {
        int cnt_dots = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '.')cnt_dots++;
        }
        if ((n - cnt_dots) % 2 == 1) {
            return false;
        }
    }
    return true;
}
void elmtarshm(int tc) {
    cin >> n >> m;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m;j++) {
            cin >> grid[i][j];
        }
    }
    if (!check_valid()) {
        cout << -1 << endl;
        return;
    }
    char ans[n][m];
    memset(ans, '.', sizeof ans);
    // handle horizontal dominoes
    for (int j = 0; j < m - 1;j++) {
        int color = 1;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'L') {
                ans[i][j] = color ? 'B' : 'W';
                ans[i][j + 1] = color ? 'W' : 'B';
                color ^= 1;
            }
        }
    }

    // handle vertical dominoes
    for (int i = 0; i < n - 1; i++) {
        int color = 1;
        for (int j = 0; j < m;j++) {
            if (grid[i][j] == 'U') {
                ans[i][j] = color ? 'B' : 'W';
                ans[i + 1][j] = color ? 'W' : 'B';
                color ^= 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
        // handle file input
        fileInput();
    init();
    int t = 1;
    cin >> t;
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
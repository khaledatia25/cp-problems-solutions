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
vector<vector<int>>g;
void init() {}

void elmtarshm(int tc) {
    int n, m, k;
    cin >> n >> m >> k;
    g.clear();
    g.assign(n + 1, vector<int>());
    vector<int>v(n + 1);
    for (int i = 1; i <= n;i++) {
        cin >> v[i];
    }
    vector<int>indeg(n + 1);
    for (int i = 1; i <= m;i++) {
        int u, v;
        cin >> u >> v;
        indeg[u]++;
        g[v].push_back(u);
    }
    vector<int>top_sort;
    max_heap<pair<int, int>>h;
    queue<int>bfs, prev;
    int start = INT_MAX;
    for (int i = 1; i <= n;i++) {
        if (indeg[i] == 0)bfs.push(i), prev.push(OO), h.push({ OO, i }), start = min(v[i], start);
    }
    vector<bool> done(n + 1);
    for (int lvl = 0;!bfs.empty(); lvl++) {
        int sz = h.size();
        while (sz--) {
            auto cur = h.top();
            h.pop();
            if (done[cur.second])continue;
            done[cur.second] = true;
            for (int nxt : g[cur.second]) {
                indeg[nxt]--;
                if (indeg[nxt] == 0) {
                    h.push({ v[cur.first], nxt });
                }
            }
        }
    }
    reverse(all(top_sort));
    for (auto I : top_sort)cout << I << space;

}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
        // handle file input
        fileInput();
    init();
    int t = 1;
    // cin >> t;
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
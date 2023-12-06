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
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_map =
    tree<T, map<T, F>, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_multimap = tree<T, map<T, F>, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &i : v) os << i << " ";
    os << '\n';
    return os;
}
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
const ll N = 1e6 + 9;

void init() {
}

void freePalestine(int tc) {
    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> g[k + 1];
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        int w = abs(u - v) * 5;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> dist(k + 1, OO);
    vector<bool> vis(k + 1, 0);
    dist[1] = 0;
    using pii = pair<int, int>;
    min_heap<pii> q;
    q.push({1, 0});
    while (!q.empty()) {
        pii cur = q.top();
        q.pop();
        if (vis[cur.first]) continue;
        vis[cur.first] = true;
        int t = cur.second;
        for (auto nxt : g[cur.first]) {
            // number of complete moves from a to b or b to a
            int times = t / nxt.second;
            int cur = t % nxt.second;
            int total = nxt.second + t;
            // true going up false giong down
            bool state = !(times % 2);
            if (!cur) {
                total += state ? 0 : nxt.second;
            } else {
                total += state ? nxt.second * 2 - cur : nxt.second - cur;
            }
            if (dist[nxt.first] > total) {
                dist[nxt.first] = total;
                q.push({nxt.first, total});
            }
        }
    }
    cout << dist[k] << endl;
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
        freePalestine(tc++);
    }

    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
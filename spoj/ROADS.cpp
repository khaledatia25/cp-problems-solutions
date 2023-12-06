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
const ll N = 1e5 + 9;
int dp[101][N];
int k, n, m;
// vector<array<int, 3>> g[101];
vector<vector<bool>> vis;
// int rec(int node, int w) {
//     if (w > k) return INT_MAX;
//     if (node == n) return 0;
//     int &ret = dp[node][w];
//     if (vis[node][w]) return ret;
//     vis[node][w] = true;
//     ret = INT_MAX;
//     for (auto nxt : g[node]) {
//         ret = min(ret, nxt[1] + rec(nxt[0], w + nxt[2]));
//     }
//     return ret;
// }

struct node {
    int n, l, cost;
    node(int n, int l, int cost) : n(n), l(l), cost(cost) {}
    bool operator<(const node &o) const {
        return l > o.l;
    }
};
vector<node> arr[101];
int dijk() {
    max_heap<node> q;
    vector<int> dis(n + 1, oo);
    node src = {1, 0, 0};
    q.push(src);
    dis[1] = 0;
    while (!q.empty()) {
        node cur = q.top();
        q.pop();
        if (cur.n == n) {
            return cur.l;
        }
        for (auto nxt : arr[cur.n]) {
            if (cur.cost + nxt.cost > k) continue;
            node to = {nxt.n, cur.l + nxt.l, cur.cost + nxt.cost};
            q.push(to);
        }
    }
    return -1;
}
void init() {
}

void freePalestine(int tc) {
    cin >> k >> n >> m;
    // A7A
    for (int i = 1; i <= n; i++) arr[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v, w, l;
        cin >> u >> v >> l >> w;
        // g[u].push_back({v, l, w});
        arr[u].push_back({v, l, w});
    }
    // vis.assign(n + 1, vector<bool>(k + 8, false));
    int ans = dijk();
    if (ans < oo)
        cout << ans << endl;
    else
        cout << -1 << endl;
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
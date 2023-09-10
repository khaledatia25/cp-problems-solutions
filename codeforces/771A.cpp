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
const ll N = 2e5 + 9;
int par[N], rk[N];
vector<int>g[N], s[N];
int find(int x) {
    if (x == par[x])return x;
    return par[x] = find(par[x]);
}
bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (rk[x] < rk[y])swap(x, y);
        par[y] = x;
        if (rk[x] == rk[y])rk[x]++;
        return true;
    }
    return false;
}
bool vis[N];
void dfs(int node) {
    vis[node] = true;
    for (auto nxt : g[node]) {
        join(node, nxt);
        if (!vis[nxt]) {
            dfs(nxt);
        }
    }
}
void init() {}

void elmtarshm(int tc) {
    int n, m;
    scanf("%lli %lli", &n, &m);
    for (int i = 1; i <= n;i++)par[i] = i, rk[i] = 1;
    for (int i = 0; i < m;i++) {
        int u, v;
        scanf("%lli %lli", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        s[find(i)].push_back(i);
    }
    for (int i = 1; i <= n;i++) {
        for (int j : s[i]) {
            if (g[j].size() != s[i].size() - 1) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");

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
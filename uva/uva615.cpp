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

void init() {}
int u, v;
void solve(int tc) {
    if (u == 0 && v == 0) {
        cout << "Case " << tc << " is a tree." << endl;
        return;
    }
    map<int, vector<int>>g;
    g[u].push_back(v);
    map<int, int>indeg;
    indeg[v]++;
    set<int>st;
    st.insert(u);
    st.insert(v);
    while (cin >> u >> v, u && v) {
        indeg[v]++;
        g[u].push_back(v);
        st.insert(u);
        st.insert(v);
    }
    int root = -1, cnt = 0;
    for (int i : st) {
        if (indeg[i] == 0) {
            root = i;
            cnt++;
        }
        if (indeg[i] > 1) {
            cout << "Case " << tc << " is not a tree." << endl;
            return;
        }
    }
    if (cnt != 1) {
        cout << "Case " << tc << " is not a tree." << endl;
        return;
    }
    queue<int>qu;
    qu.push(root);
    map<int, bool> vis;
    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();
        if (vis[cur]) {
            cout << "Case " << tc << " is not a tree." << endl;
            return;
        }
        vis[cur] = true;
        for (auto nxt : g[cur]) {
            qu.push(nxt);
        }
    }
    for (int i : st) {
        if (!vis[i]) {
            cout << "Case " << tc << " is not a tree." << endl;
            return;
        }
    }
    cout << "Case " << tc << " is a tree." << endl;

}

void elmtarshm(int tc) {
    while (cin >> u >> v) {
        if (u <= -1 && v <= -1) {
            break;

        }
        solve(tc++);
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
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
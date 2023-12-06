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
    int n;
    while (cin >> n) {
        vector<int> g[n + 1];
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        for (int u = 1; u <= n; u++) {
            int k;
            cin >> k;
            while (k--) {
                int v;
                cin >> v;
                cnt[u]++;
                g[u].push_back(v);
            }
        }
        queue<int> qu;
        set<int> st;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 1) {
                qu.push(i);
            }
            st.insert(i);
        }
        for (int level = 1; !qu.empty(); level++) {
            int sz = qu.size();
            while (sz--) {
                int cur = qu.front();
                qu.pop();
                st.erase(cur);
                for (int nxt : g[cur]) {
                    cnt[nxt]--;
                    if (cnt[nxt] == 1) {
                        qu.push(nxt);
                    }
                }
            }
            if (st.size() == 2 || st.size() == 1) {
                break;
            }
        }
        vector<int> dist(n + 1);
        function<void(int, int, int)> dfs = [&](int node, int par, int depth) {
            dist[node] = depth;
            for (int nxt : g[node]) {
                if (nxt == par) continue;
                dfs(nxt, node, depth + 1);
            }
        };
        vector<int> worst;
        cout << "Best Roots  :";
        for (auto i : st) {
            cout << space;
            cout << i;
            dfs(i, i, 0);
            int w = *max_element(all(dist));
            for (int i = 1; i <= n; i++)
                if (dist[i] == w) worst.push_back(i);
        }
        cout << endl;
        cout << "Worst Roots :";
        sort(all(worst));
        for (int i : worst) cout << space << i;
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
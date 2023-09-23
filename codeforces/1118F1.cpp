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
const ll N = 1e4 + 9;

void init() {}

void elmtarshm(int tc) {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (v[i] == 1) {
      cnt1++;
    }
    if (v[i] == 2) {
      cnt2++;
    }
  }
  vector<int> dp1(n + 1), dp2(n + 1);
  for (int i = 1; i <= n; i++) {
    if (v[i] == 1) dp1[i] = 1;
    if (v[i] == 2) dp2[i] = 1;
  }
  vector<int> g[n + 1];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  function<void(int, int)> dfs = [&](int node, int parent) {
    for (int nxt : g[node]) {
      if (nxt == parent) continue;
      dfs(nxt, node);
      dp1[node] += dp1[nxt];
      dp2[node] += dp2[nxt];
    }
  };
  dfs(1, 1);
  set<pair<int, int>> st;
  function<void(int, int)> dfs1 = [&](int node, int parent) {
    for (int nxt : g[node]) {
      if (nxt == parent) continue;
      if (dp1[nxt] == cnt1 && dp2[nxt] == 0) {
        st.insert({min(node, nxt), max(node, nxt)});
      }
      if (dp2[nxt] == cnt2 && dp1[nxt] == 0) {
        st.insert({min(node, nxt), max(node, nxt)});
      }
      dfs1(nxt, node);
    }
  };
  dfs1(1, 1);
  cout << st.size() << endl;
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
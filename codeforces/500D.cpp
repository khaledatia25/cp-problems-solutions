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
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T> using max_heap = priority_queue<T>;
template <class T> istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v)
    is >> i;
  return is;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto &i : v)
    os << i << " ";
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
vector<pair<int, int>> g[N];
int cnt[N];
int n;
int sum = 0;
map<pair<int, int>, bool> mp;
void dfs(int node = 1, int parent = -1) {
  cnt[node] = 1;
  for (auto nxt : g[node]) {
    if (nxt.first == parent)
      continue;
    dfs(nxt.first, node);
    mp[{node, nxt.first}] = true;
    sum += cnt[nxt.first] * (n - cnt[nxt.first]) * nxt.second;
    cnt[node] += cnt[nxt.first];
  }
}
void init() {}

void elmtarshm(int tc) {
  cin >> n;
  vector<array<int, 3>> a(n);
  for (int i = 1; i < n; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    g[u].push_back({v, l});
    g[v].push_back({u, l});
    a[i] = {u, v, l};
  }
  dfs();
  int q;
  cin >> q;
  while (q--) {
    int i, w;
    cin >> i >> w;
    auto &cur = a[i];
    if (!mp[{cur[0], cur[1]}]) {
      swap(cur[0], cur[1]);
    }
    int u = cur[0], v = cur[1], old_w = cur[2];
    sum -= cnt[v] * (n - cnt[v]) * old_w;
    cur[2] = w;
    sum += cnt[v] * (n - cnt[v]) * w;
    double ans = 3.0 * 2.0 * sum  / (n * (n-1));
    prec(10);
    cout<<ans<<endl;
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
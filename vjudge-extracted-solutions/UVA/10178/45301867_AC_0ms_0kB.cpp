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
map<char, char> par;
map<char, int> rk, cnt;
char get(char x) {
  if (x == par[x]) return x;
  return par[x] = get(par[x]);
}
int join(char x, char y) {
  x = get(x);
  y = get(y);
  if (x == y) return false;
  if (rk[x] < rk[y]) swap(x, y);
  par[y] = x;
  cnt[x] += cnt[y];
  if (rk[y] == rk[x]) rk[x]++;
  return true;
}
void reset() {
  par.clear();
  rk.clear();
  cnt.clear();
  for (char c = 'a'; c <= 'z'; c++) {
    par[c] = c;
    rk[c] = 1;
    cnt[c] = 1;
  }
  for (char c = 'A'; c <= 'Z'; c++) {
    par[c] = c;
    rk[c] = 1;
    cnt[c] = 1;
  }
}
void init() {}

void elmtarshm(int tc) {
  int n, m;
  while (cin >> n >> m) {
    reset();
    set<char> st;
    map<pair<char, char>, int> edges;
    for (int i = 0; i < m; i++) {
      char u, v;
      cin >> u >> v;
      edges[{u, v}]++;
      st.insert(u);
      st.insert(v);
      join(u, v);
    }
    map<char, pair<int, int>> component;
    for (auto c : st) {
      char p = get(c);
      component[p] = {cnt[p], 0};
    }
    int ans = 1;
    for (auto c1 : st) {
      for (auto c2 : st) {
        if (edges.count({c1, c2})) component[get(c1)].second += edges[{c1, c2}];
      }
    }
    for (auto k : component) {
      auto p = k.second;
      int v = p.first;
      int e = p.second;
      ans += e - v + 1;
    }
    cout << ans << endl;
  }
}

int32_t main() {
  // fast input
  KHALED_WALEED_ATTIA
  // handle file input
  // fileInput();
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
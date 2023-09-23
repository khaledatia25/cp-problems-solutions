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
  int n, k;
  cin >> n >> k;
  vector<int> g[n + 1];
  vector<int> cnt(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    cnt[u]++;
    cnt[v]++;
  }
  queue<int> qu;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) {
      qu.push(i);
    }
  }
  int ans = 0;
  for (int i = 0; k && qu.size(); i++) {
    int sz = qu.size();
    while (sz--) {
      int cur = qu.front();
      qu.pop();
      ans++;
      for (int nxt : g[cur]) {
        cnt[nxt]--;
        if (cnt[nxt] == 1) {
          qu.push(nxt);
        }
      }
    }
    k--;
  }
  ans = n - ans;
  if(ans == 1 &&k )cout<<0<<endl;
  else cout<<ans<<endl;
  // function<pair<int, int>(int, int, int)> dfs1 = [&](int node, int parent,
  //                                                    int depth) {
  //   pair<int, int> ret = {node, depth};
  //   for (int nxt : g[node]) {
  //     if (nxt == parent) continue;
  //     auto temp = dfs1(nxt, node, depth + 1);
  //     if (temp.second > ret.second) {
  //       ret = temp;
  //     }
  //   }
  //   return ret;
  // };
  // auto l = dfs1(1, 1, 0);
  // auto r = dfs1(l.first, l.first, 0);
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
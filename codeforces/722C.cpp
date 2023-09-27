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
  vector<int> v(n);
  cin >> v;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  vector<bool> nd(n);
  vector<int> pre = v;
  for (int i = 1; i < n; i++) pre[i] += pre[i - 1];
  auto get = [&](int l, int r) { return l ? pre[r] - pre[l - 1] : pre[r]; };
  map<int, int> mp;
  mp[n - 1] = 0;
  multiset<int> ms;
  ms.insert(get(0, n - 1));
  ms.insert(0);
  for (int j : a) {
    auto it = mp.lower_bound(j);
    if (it == mp.end()) {
      cout << 0 << endl;
      break;
    }
    if (it->first == j) {
      ms.erase(ms.find(get(mp[j], j)));
      if (j && it->first != it->second) {
        mp[j - 1] = mp[j];
        ms.insert(get(mp[j - 1], j - 1));
      }
      mp.erase(j);
    } else {
      ms.erase(ms.find(get(it->second, it->first)));
      int st = it->second;
      int nd = j - 1;
      int st1 = j + 1;
      int nd1 = it->first;
      mp.erase(it->first);
      if (st <= nd && nd < n) {
        mp[nd] = st;
        ms.insert(get(st, nd));
      }
      if (st1 <= nd1 && nd1 < n) {
        mp[nd1] = st1;
        ms.insert(get(st1, nd1));
      }
    }
    cout << *ms.rbegin() << endl;
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
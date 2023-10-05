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
const ll N = 1e4 + 9;

void init() {}

void elmtarshm(int tc) {
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  cin >> v;
  auto pre1 = v;
  for (int i = 1; i < n; i++)
    pre1[i] += pre1[i - 1];
  auto pre2 = v;
  for (int i = 1; i < n; i++)
    pre2[i] ^= pre2[i - 1];
  auto sum = [&](int l, int r) { return l ? pre1[r] - pre1[l - 1] : pre1[r]; };
  auto xr = [&](int l, int r) { return l ? pre2[r] ^ pre2[l - 1] : pre2[r]; };
  while (q--) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    int val = sum(L, R) - xr(L, R);
    int l = L, r = R;
    for (int i = L; i <= R; i++) {
      int st = i, nd = R, a = -1;
      while (st <= nd) {
        int mid = (st + nd) / 2;
        int temp = sum(i, mid) - xr(i, mid);
        if (temp >= val) {
          nd = mid - 1;
          a = mid;
        } else {
          st = mid + 1;
        }
      }
      if (a == -1)
        continue;
      if (a - i + 1 < r - l + 1) {
        l = i, r = a;
      }
    }
    cout << l + 1 << space << r + 1 << endl;
  }
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
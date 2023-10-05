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
/*
  a , b
  l , r
  find number of x -> l <= x <= r
  such that x%a %b != x %b %a
  any x < a && x < b -> x%a %b == x%b %a

  7 mod 3 = 1
  7 mod 5 = 2
  a = 3,  b = 5
  i  %a%b %b%a
  1  1  1
  2  2  2
  3  0  0
  4  1  1
  5  2  0
  6  0  1
  7  1  2
  8  2  0
  9  0  1
  10  1  0
  11  2  1
  12  0  2
  13  1  0
  14  2  1
  15  0  0
  16  1  1 -> cycle
  17  2  2
  18  0  0
  19  1  1
  20  2  0

*/

void init() {}

void elmtarshm(int tc) {
  int n, a, b, q;
  cin >> a >> b >> q;
  vector<int> pre(a * b + 1);
  for (int i = 1; i <= a * b; i++)
    pre[i] = pre[i - 1] + (i % a % b != i % b % a);
  auto query = [&](int r) {
    return r / (a * b) * pre.back() + pre[r % (a * b)];
  };
  for (; q; q--) {
    int l, r;
    cin >> l >> r;
    cout << query(r) - query(l - 1) << space;
  }
  cout << endl;
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
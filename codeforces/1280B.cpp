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
  int r, c;
  cin >> r >> c;
  vector<vector<char>> grid(r, vector<char>(c));
  int cnt = 0;
  for (auto &row : grid) {
    for (auto &cell : row) {
      cin >> cell;
      if (cell == 'A') cnt++;
    }
  }
  if (cnt == 0) {
    cout << "MORTAL" << endl;
    return;
  }
  if (cnt == r * c) {
    cout << 0 << endl;
    return;
  }
  int f1 = 0, l1 = 0;
  for (int i = 0; i < c; i++) {
    if (grid[0][i] == 'A') {
      f1++;
    }
    if (grid[r - 1][i] == 'A') {
      l1++;
    }
  }
  if (f1 == c || l1 == c) {
    cout << 1 << endl;
    return;
  }
  int f2 = 0, l2 = 0;
  for (int i = 0; i < r; i++) {
    if (grid[i][0] == 'A') {
      f2++;
    }
    if (grid[i][c - 1] == 'A') {
      l2++;
    }
  }
  if (f2 == r || l2 == r) {
    cout << 1 << endl;
    return;
  }
  for (int i = 0; i < r; i++) {
    int cnt = count(all(grid[i]), 'A');
    if (cnt == c) {
      cout << 2 << endl;
      return;
    }
  }
  for (int j = 0; j < c; j++) {
    int cnt = 0;
    for (int i = 0; i < r; i++) {
      if (grid[i][j] == 'A') cnt++;
    }
    if (cnt == r) {
      cout << 2 << endl;
      return;
    }
  }
  if (grid[0][0] == 'A' || grid[r - 1][0] == 'A' || grid[0][c - 1] == 'A' ||
      grid[r - 1][c - 1] == 'A') {
    cout << 2 << endl;
    return;
  }
  if (f1 || f2 || l1 || l2) {
    cout << 3 << endl;
    return;
  }
  cout << 4 << endl;
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
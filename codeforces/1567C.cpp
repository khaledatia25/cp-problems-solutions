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
int dp[10][5][5];
int length;
string s;
int rec(int i, int c1, int c2) {
  if (i >= length) {
    return !c1 && !c2;
  }
  int &ret = dp[i][c1][c2];
  if (~ret) return ret;
  ret = 0;
  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 10; b++) {
      int cur = (a + b + c2) % 10;
      int c = (a + b + c2) / 10;
      if (cur == s[i] - '0') ret += rec(i + 1, c, c1);
    }
  }
  return ret;
}
void init() {}

void elmtarshm(int tc) {
  int n;
  cin >> n;
  s = to_string(n);
  string a, b;
  for (int i = 0; i < s.size(); i++) {
    if (i & 1)
      a.push_back(s[i]);
    else
      b.push_back(s[i]);
  }
  if (a.size() == 0) a.push_back('0');
  if (b.size() == 0) b.push_back('0');
  int x = stoi(a);
  int y = stoi(b);
  x++, y++;
  // sol-1
  // cout<<x*y-2<<endl;
  length = s.size();
  memset(dp, -1, sizeof dp);
  reverse(all(s));
  // sol-2
  cout << rec(0, 0, 0) - 2 << endl;
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
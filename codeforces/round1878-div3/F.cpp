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
vector<int> primef(int num) {
  vector<int> ret;
  for (int i = 2; i * i <= num; i++) {
    while (num % i == 0) {
      ret.push_back(i);
      num /= i;
    }
  }
  if (num != 1)
    ret.push_back(num);
  return ret;
}
void init() {}

void elmtarshm(int tc) {
  int n, q;
  cin >> n >> q;
  map<int, int> cnt;
  auto a1 = primef(n);
  int d = 1;
  for (int i : a1)
    cnt[i]++;
  for (auto i : cnt) {
    d *= i.second + 1;
  }
  int cur = n;
  while (q--) {
    int op;
    cin >> op;
    if (op == 2) {
      cnt.clear();
      d = 1;
      for (auto I : a1)
        d /= cnt[I] + 1, cnt[I]++, d *= cnt[I] + 1;

    } else {
      int x;
      cin >> x;
      auto a2 = primef(x);
      for (auto I : a2)
        d /= cnt[I] + 1, cnt[I] += 1, d *= cnt[I] + 1;
      auto a3 = primef(d);
      bool a = true;
      for (int i : a3) {
        cnt[i]--;
        if (cnt[i] < 0) {
          a = false;
        }
      }
      for (int i : a3) {
        cnt[i]++;
      }
      cout << (a ? "YES" : "NO") << endl;
    }
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
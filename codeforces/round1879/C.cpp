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
struct segaya {
  int size;
  vector<int> seg, lazy;
  vector<bool> marked;
  int NUTRL = 0;
  void init(int n) {
    size = n + 5;
    while (countbits(size) != 1) ++size;
    seg = vector<int>(2 * size);
    lazy = vector<int>(2 * size, 0);
    marked = vector<bool>(2 * size, 0);
  }

  void build(vector<int> &numbers, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < numbers.size()) {
        seg[x] = numbers[lx];
      }
      return;
    }
    int mid = lx + rx >> 1;
    build(numbers, 2 * x + 1, lx, mid);
    build(numbers, 2 * x + 2, mid, rx);
    seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
  }
  void build(vector<int> &numbers) { build(numbers, 0, 0, size); }

  void push(int x, int lx, int rx) {
    if (!marked[x]) return;
    seg[x] = lazy[x];
    if (rx - lx > 1) {
      lazy[2 * x + 1] = lazy[x];
      marked[2 * x + 1] = 1;

      lazy[2 * x + 2] = lazy[x];
      marked[2 * x + 2] = 1;
    }
    lazy[x] = 0;
    marked[x] = 0;
  }

  void update(int l, int r, int val, int x, int lx, int rx) {
    push(x, lx, rx);
    if (lx >= r || l >= rx) {
      return;
    }
    if (lx >= l && rx <= r) {
      lazy[x] = val;
      marked[x] = 1;
      push(x, lx, rx);
      return;
    }
    int mid = lx + rx >> 1;
    update(l, r, val, 2 * x + 1, lx, mid);
    update(l, r, val, 2 * x + 2, mid, rx);
    seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
  }

  void update(int l, int r, int val) { update(l, r, val, 0, 0, size); }

  int get(int l, int r, int x, int lx, int rx) {
    push(x, lx, rx);
    if (lx >= r || l >= rx) {
      return NUTRL;
    }
    if (lx >= l && rx <= r) {
      return seg[x];
    }
    int mid = lx + rx >> 1;
    auto L = get(l, r, 2 * x + 1, lx, mid);
    auto R = get(l, r, 2 * x + 2, mid, rx);
    return max(L, R);
  }
  int get(int l, int r) { return get(l, r, 0, 0, size); }
};
void init() {}

void elmtarshm(int tc) {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  vector<int> a(k + 1);
  cin >> v;
  v.insert(v.begin(), 0);
  segaya f, b;
  f.init(k + 10);
  for (int i = 1; i <= n; i++) {
    a[v[i]] = true;
    f.update(0, v[i] + 1, i);
  }
  b.init(k + 10);
  for (int i = n; i >= 1; i--) {
    b.update(0, v[i] + 1, i);
  }
  for (int i = 1; i <= k; i++) {
    int r = f.get(i, i + 1);
    int l = b.get(i, i + 1);
    cout << (a[i] ? 2 * (r - l + 1) : 0) << space;
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
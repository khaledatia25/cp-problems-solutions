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
struct node {
  int val;
};
struct segaya {
  int size = 1;
  vector<node> tree;
  node nutral = {-1};

  node single(int number) { return {number}; }

  node merge(node &l, node &r) { return {l.val & r.val}; }

  void init(int n) {
    while (size < n)
      size *= 2;

    tree.assign(size * 2 + 9, nutral);
  }

  void build(vector<int> &numbers, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < numbers.size()) {

        tree[x] = single(numbers[lx]);
      }
      return;
    }
    int mid = (lx + rx) / 2;
    int left = 2 * x + 1;
    int right = 2 * x + 2;
    build(numbers, left, lx, mid);
    build(numbers, right, mid, rx);
    tree[x] = merge(tree[left], tree[right]);
  }

  void build(vector<int> &numbers) { build(numbers, 0, 0, size); }

  void update(int i, int number, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = single(number);
      return;
    }
    int mid = (lx + rx) / 2;
    int right = 2 * x + 2;
    int left = 2 * x + 1;
    if (i < mid) {
      update(i, number, left, lx, mid);
    } else {
      update(i, number, right, mid, rx);
    }
    tree[x] = merge(tree[left], tree[right]);
  }
  void update(int i, int number) { update(i, number, 0, 0, size); }

  node get(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) {
      return nutral;
    }
    if (lx >= l && rx <= r) {
      return tree[x];
    }
    int mid = (lx + rx) / 2;
    int left = 2 * x + 1;
    int right = 2 * x + 2;
    node leftSeg = get(l, r, left, lx, mid);
    node rightSeg = get(l, r, right, mid, rx);
    return merge(leftSeg, rightSeg);
  }

  node get(int l, int r) { return get(l, r, 0, 0, size); }
};
void init() {}

void elmtarshm(int tc) {
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  segaya sg;
  sg.init(n);
  sg.build(v);
  int q;
  cin >> q;
  while (q--) {
    int l, k;
    cin >> l >> k;
    l--;
    int st = l, nd = n - 1;
    int ans = -2;
    while (st <= nd) {
      int mid = (st + nd) / 2;
      int val = sg.get(l, mid + 1).val;
      if (val >= k) {
        st = mid + 1;
        ans = mid;
      } else {
        nd = mid - 1;
      }
    }
    cout << ans+1 << space;
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
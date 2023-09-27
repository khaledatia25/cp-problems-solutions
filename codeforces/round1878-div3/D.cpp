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
const int maxn = 200010;
const int inf = 1000000000;
struct node {
  node *L, *R;
  int W, S;
  char V;
  bool F;
  node(char x) {
    L = R = 0;
    W = rand();
    S = 1;
    V = x;
    F = 0;
  }
};

int size(node *treap) { return (treap == 0 ? 0 : treap->S); }

void push(node *treap) {
  if (treap && treap->F) {
    treap->F = 0;
    swap(treap->L, treap->R);
    if (treap->L)
      treap->L->F ^= 1;
    if (treap->R)
      treap->R->F ^= 1;
  }
}

void split(node *treap, node *&left, node *&right, int k) {
  if (treap == 0)
    left = right = 0;
  else {
    push(treap);
    if (size(treap->L) < k) {
      split(treap->R, treap->R, right, k - size(treap->L) - 1);
      left = treap;
    } else {
      split(treap->L, left, treap->L, k);
      right = treap;
    }
    treap->S = size(treap->L) + size(treap->R) + 1;
  }
}

void merge(node *&treap, node *left, node *right) {
  if (left == 0)
    treap = right;
  else if (right == 0)
    treap = left;
  else {
    push(left);
    push(right);
    if (left->W < right->W) {
      merge(left->R, left->R, right);
      treap = left;
    } else {
      merge(right->L, left, right->L);
      treap = right;
    }
    treap->S = size(treap->L) + size(treap->R) + 1;
  }
}

void print(node *treap) {
  if (treap == NULL)
    return;
  push(treap);
  print(treap->L);
  cout << treap->V;
  print(treap->R);
}
void init() {}

void elmtarshm(int tc) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int m;
  map<int, int> l;
  vector<pair<int, int>> vp(k);
  for (int i = 0; i < k; i++)
    cin >> vp[i].first;
  for (int i = 0; i < k; i++)
    cin >> vp[i].second;
  for (auto I : vp) {
    l[I.second] = I.first;
  }
  int q;
  cin >> q;
  map<int, int> r;
  node *treap = 0;
  for (auto i : s) {
    merge(treap, treap, new node(i));
  }
  while (q--) {
    int x;
    cin >> x;
    node *A, *B, *C;
    auto it = l.lower_bound(x);
    int L = it->second;
    int R = it->first;
    int a = min(x, L + R - x);
    int b = max(x, L + R - x);
    split(treap, A, B, a - 1);
    split(B, B, C, b - a + 1);
    B->F ^= 1;
    merge(treap, A, B);
    merge(treap, treap, C);
  }
  print(treap);
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
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
// const ll mod = 1e9 + 7;
const ll mod = 998244353;
// const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 3e5 + 9;
int f[N];
ll modular_expo(ll x, ll n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = ((res % m) * (x % m)) % m;
    x = ((x % m) * (x % m)) % m;
    n = n / 2;
  }
  return res % m;
}
ll mod_inverse(ll a, ll mod) { return modular_expo(a, mod - 2LL, mod); }
int nCr(int n, int r) {
  return (f[n] * mod_inverse(f[n - r] * f[r] % mod, mod)) % mod;
}
void init() {
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i < N; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
}

void elmtarshm(int tc) {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  // sum1 -> (r - l + 1)
  int sum1 = 0;
  for (int i = 1; i <= n; i++) {
    sum1 = (sum1 + nCr(n, i) * i % mod) % mod;
  }
  // sum2 -> f(l, r)
  vector<int> c(n);
  int sum2 = 0;
  int mul = 1;
  for (int i = 0; i < 30; i++) {
    int odd = 0;
    bool o = false;
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << i)) {
        o = !o;
      }
      if (o) odd++;
    }
    for (int j = 0; j < n; j++) {
      int temp = (j + 1) * (j + 2) / 2 + (n - j) * (n - j - 1) / 2 - 1;
      sum2 = (sum2 + mul * odd * temp) % mod;
      if (a[j] & (1 << i)) {
        odd = (n - j - odd);
      }
    }
    mul *= 2;
  }
  cout << sum2 << endl;
}

int32_t main() {
  // fast input
  KHALED_WALEED_ATTIA
  // handle file input
  fileInput();
  init();
  int t = 1;
  //  cin >> t;
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
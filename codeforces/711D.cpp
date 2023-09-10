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
const ll N = 2e5 + 9;
int nxt[N], vis[N];
vector<int> cycles;
int c = 0;
int dfs1(int node) {
  vis[node] = 3;
  if (vis[nxt[node]] == 3)
    return 1;
  else
    return 1 + dfs1(nxt[node]);
}
void dfs(int node) {
  vis[node] = 1;
  if (vis[nxt[node]] == 0) {
    dfs(nxt[node]);
  } else if (vis[nxt[node]] == 2) {
    vis[node] = 2;
    return;
  } else {
    int cnt = dfs1(node);
    c = 0;
    cycles.push_back(cnt);
  }
  vis[node] = 2;
}

int power(int base, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = ret * base % mod;
    base = base * base % mod;
    p >>= 1;
  }
  return ret;
}
int mul(int a, int b) { return a * b % mod; }
int add(int a, int b) { return (a % mod + b % mod + mod) % mod; }
void init() {}
void elmtarshm(int tc) {
  int n;
  cin >> n;
  memset(nxt, -1, sizeof nxt);
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  int cnt = n;
  for (int i : cycles) {
    cnt -= i;
    ans = mul(ans, add(power(2, i), -2));
  }
  ans = mul(ans, power(2, cnt));
  cout << ans << endl;
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
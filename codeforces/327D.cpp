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
const ll N = 5e2 + 9;
char grid[N][N];
bool vis[N][N];
vector<pair<int, int>> component;
int n, m;
struct out {
  char c;
  int x, y;
  out(char c, int x, int y) : c(c), x(x), y(y) {}
  void p() { cout << c << space << x << space << y << endl; }
};
vector<out> ans;
bool valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
}
int sx, sy;
void dfs(int x, int y) {
  ans.push_back({'B', x + 1, y + 1});
  vis[x][y] = true;
  for (int d = 0; d < 4; d++) {
    int i = x + dx[d];
    int j = y + dy[d];
    if (valid(i, j) && !vis[i][j]) {
      dfs(i, j);
    }
  }
  if (x == sx && y == sy) return;
  ans.push_back({'D', x + 1, y + 1});
  ans.push_back({'R', x + 1, y + 1});
}

void init() {}
void elmtarshm(int tc) {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (valid(i, j) && !vis[i][j]) {
        sx = i;
        sy = j;
        dfs(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto I : ans) {
    I.p();
  }
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
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
void file_input();
int n, k;
int a[(int)1e5], b[(int)1e5];

bool pred(int cookies) {
  ll need = 0;
  for (int i = 0; i < n; i++) {
    if (cookies * a[i] <= b[i]) continue;
    need += cookies * a[i] - b[i];
  }
  return need <= k;
}
double p, q, r, s, t, u;
double f(int x) {
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
  
}
const double EPS = 1e-9;
void solve() {
  int st = 0, nd = 1.0;
  for (int i = 0; i < 100; i++) {
    double mid = (nd + st) / 2.0;
    if (f(mid) < 0) {
      st = mid;
    } else {
      nd = mid;
    }
  }
  cout << st << endl;
}

signed main() {
  int t = 1;
  // cin >> t;

  while (t--) solve();

  return 0;
}

void file_input() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
}
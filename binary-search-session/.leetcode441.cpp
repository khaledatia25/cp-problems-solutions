#include <bits/stdc++.h>
#define int long long
using namespace std;
void file_input();
int n;
bool can(int r) { return n >= r * (r + 1) / 2; }
void solve() {
  cin >> n;
  int st = 0, nd = 1e6 + 1;
  int ans = 0;
  while (st <= nd) {
    int mid = (st + nd) / 2;
    if (can(mid)) {
      st = mid + 1;
      ans = mid;
    } else {
      nd = mid - 1;
    }
  }
  cout << ans << endl;
}

signed main() {
  int t = 1;
  file_input();
  cin >> t;

  while (t--) solve();

  return 0;
}

void file_input() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
}
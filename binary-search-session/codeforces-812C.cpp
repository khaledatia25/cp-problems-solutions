#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
/*
    We will make binary search on number of souv. we buy
    If we are able to buy k souv then we are able to buy k-1 souv
    If we are not able to buy l souv then we are not able to buy l+1 souv
    This is a monotonic function we can make binry search
*/
ll calc(int mid, vector<ll>& a, ll s) {
  vector<ll> temp = a;
  for (int i = 0; i < a.size(); i++) {
    temp[i] += mid * (i + 1);
  }
  sort(temp.begin(), temp.end());
  ll sum = accumulate(temp.begin(), temp.begin() + mid, 0ll);
  return sum;
}

bool pred(int mid, vector<ll>& a, ll s) {
  ll sum = calc(mid, a, s);
  return sum <= s;
}

void file_input();
void solve() {
  int n, s;
  cin >> n >> s;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int st = 0, nd = n;
  int ans = 0, cost = 0;
  while (st <= nd) {
    int mid = (st + nd) / 2;
    if (pred(mid, a, s)) {
      st = mid + 1;
      ans = mid;
      cost = calc(mid, a, s);
    } else {
      nd = mid - 1;
    }
  }
  cout << ans << " " << cost << endl;
}

signed main() {
  int t = 1;
  file_input();
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
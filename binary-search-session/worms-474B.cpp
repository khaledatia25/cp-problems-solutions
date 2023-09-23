#include <bits/stdc++.h>

using namespace std;
void file_input();

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i += 1) {
    cin >> v[i];
  }
  for(int i = 1;i<n;i++)v[i]+=v[i-1];
  int q;
  cin>>q;
  while(q--){
    int index;
    cin>>index;
    cout<<lower_bound(v.begin(), v.end(), index) - v.begin() + 1<<endl;
  }
}

signed main() {
  file_input();
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
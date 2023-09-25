/*
  Hint-1 -> how can we know maximum index in each pile ?
  Hint-2 -> how we can use the previous information to find the pile that the index belongs to ?
*/
#include <bits/stdc++.h>

using namespace std;
void file_input();








/*
  Solution
    - We will make prefix sum on the given array now we know that v[i] is equal to maximum index in the box i
    - The index is in the box i if and only if index <= v[i] and index > v[i-1]
    - This means we search for the first maximum value that make index <= v[i] -> lower bound 
*/
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 1; i < n; i++) v[i] += v[i - 1];
  int m;
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    cout << lower_bound(v.begin(), v.end(), x) - v.begin() + 1 << endl;
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
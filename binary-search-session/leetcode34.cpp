#include <bits/stdc++.h>

using namespace std;
void file_input();

vector<int> searchRange(vector<int>& nums, int target) {
  /*
    code here
  */
}

void solve() {
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int test1 = 8, test2 = 6;
  auto ans1 = searchRange(nums, test1);
  cout << "Test - 1 answer is " << ans1[0] << " " << ans1[1] << endl;
  auto ans2 = searchRange(nums, test2);
  cout << "Test - 2 answer is " << ans2[0] << " " << ans2[1] << endl;
}

signed main() {
  int t = 1;
  //   cin >> t;

  while (t--) solve();

  return 0;
}

void file_input() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
}
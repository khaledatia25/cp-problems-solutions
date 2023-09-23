#include <bits/stdc++.h>

using namespace std;
void file_input();

int search(vector<int>& nums, int target) {
  /*
    code here
  */
  auto low = lower_bound(nums.begin(), nums.end(), target);
  auto high = upper_bound(nums.begin(), nums.end(), target);
  if (low == high) {
    cout << "-1 -1";
  } else {
    cout << low - nums.begin() << " " << high - nums.begin() - 1 << endl;
  }
}

void solve() {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int test1 = 9, test2 = 2;
  cout << "Test - 1 answer is " << search(nums, test1) << endl;
  cout << "Test - 2 answer is " << search(nums, test2) << endl;
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
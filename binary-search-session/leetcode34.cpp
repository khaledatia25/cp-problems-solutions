#include <bits/stdc++.h>
using namespace std;
/*
  Idea find first index and last index of target in the given vector
  Solution -> find first index using lower bound
           -> find last index using upper bound - 1
           -> if lower bound = upper bound there is no elements in the vector
  equal target


*/
void file_input();

vector<int> searchRange(vector<int>& nums, int target) {
  auto it1 = lower_bound(nums.begin(), nums.end(), target);
  auto it2 = upper_bound(nums.begin(), nums.end(), target);

  if (it1 == it2) {
    return {-1, -1};
  } else {
    int i1 = it1 - nums.begin();
    int i2 = it2 - nums.begin() - 1;
    return {i1, i2};
  }
}

void solve() {}

signed main() {
  int t = 1;
  file_input();
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
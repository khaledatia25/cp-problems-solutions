#include <bits/stdc++.h>

using namespace std;
void file_input();
/*
https://leetcode.com/problems/binary-search/
*/
void solve() {
  vector<int> nums = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
  int start = 0, end = nums.size() - 1, target = 37;
  int index = -1;
  while(start <= end){
    int mid = (start + end)/2;
    if(nums[mid] == target){
      index = mid;
      break;
    }else if(nums[mid] < target) {
      start = mid + 1;
    }else {
      end = mid - 1;
    }
  }
  if(index == -1) 
    cout<<"Element Doesn't exist in the array"<<endl;
  else
    cout<<"Index of element is "<<index<<endl; 

}
  
signed main() {
  int t = 1;
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
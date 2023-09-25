#include <bits/stdc++.h>

using namespace std;
void file_input();
/*
  - In this problem we can ovserve the monotonicity of the fucntion we search for 
  - It is so clear that if we can make 5 complete rows we surly can make 4 complete rows
  - and if we cannot make 6 complete rows we surly cannot make 7 complete rows
  - our fucntion will be like this 
  - T T T T T T F F F F F F
  - Here we search for the last true
  
  - our code will work as follows
  - start to search for the maximum number of complete rows we can make 
  - in each step we compare number of coins we have with number of coins required to make (r) complete rows
  - if f(r) <= n we are sure that we can make  any number of rows <= r so we move  after r -> st = mid + 1
  - else we are sure that we cannot make any number of rows >= r so we move to search before r -> nd = mid - 1

*/

class Solution {
 public:
  long long f(long long r) { return 1ll * r * (r + 1) / 2; }
  bool pred(long long rows, long long n) { return f(rows) <= n; }
  int arrangeCoins(int n) {
    long long st = 0, nd = 1e5 + 1;
    long long ans = 0;
    // T T T T F F F ...
    while (st <= nd) {
      int mid = (st + nd) / 2;
      if (pred(mid, n)) {
        ans = mid;
        st = mid + 1;
      } else {
        nd = mid - 1;
      }
    }
    return ans;
  }
};
void solve() {}

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
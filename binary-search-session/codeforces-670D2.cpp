#include <bits/stdc++.h>
#define ll long long
using namespace std;
void file_input();
/*
    We will use binary search on the answer technique to solve this problem
        - first thing to think about if I wanted to make c number of cookies can I know if it is possible or not?
        - second thing to think about if I can make 4 cookies can I make 3?
        - if I cannot make 7 can I make 8 ?

    
    First 
        we can know if I am able to make particular number of cookies (c) easily in linear time
        we will go throw each ingredient -> the amount I need from each ingredient is (c * a[i]) and I already
        have b[i] from this ingredient so if b[i] >= (c*a[i]) I dont need to use magic powder for this ingredient
        otherwise I need to convert (c*a[i] - b[i]) from the magic poweder to the indredient i
        so we can sum total amount needed from the magic powder -> need  
        if need <= k then we can make this c cookies
        else we cannot make c cookies 
    Second 
        It is clear that if I can make 5 cookies, I surly can  make 4 cookies 
        If I cannot make 7 cookies, I surly cannot make 8 cookies
        T T T T T T T F F F F F F F F 
*/

const int N = 1e5 + 8;
ll a[N], b[N];
ll n, k;
bool pred(ll cookies) {
  ll temp = k;
  for (int i = 0; i < n; i++) {
    if (a[i] * cookies > b[i]) {
    //  WE USE MINUS TO AVOID OVERFLOW
      temp -= (a[i] * cookies - b[i]);
    }
    if (temp < 0) return false;
  }
  return temp >= 0;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  ll st = 0, nd = 1e10;
  ll ans = 0;
  while (st <= nd) {
    ll mid = (st + nd) / 2;
    if (pred(mid)) {
      ans = mid;
      st = mid + 1;
    } else {
      nd = mid - 1;
    }
  }
  cout << ans << endl;
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
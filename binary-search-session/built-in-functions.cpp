#include <bits/stdc++.h>

using namespace std;
void file_input();

void solve() {
  vector<int> v = {1,  3,  5,  7,  11, 13, 17, 19, 23,
                   29, 31, 37, 37, 37, 37, 41, 43, 47};

 
  // binary_search(_first_iterator, _second_iterator, _val)
  // returns true if target is present in the vector, otherwise false.
  cout << binary_search(v.begin(), v.end(), 37) << endl;  // -> true
  cout << binary_search(v.begin(), v.end(), 9) << endl;   // -> false




  // lower_bound(_first_iterator, _second_iterator, _val)
  // returns an iterator of the first element greater than or equal to _val
  // if there is no element return iterator to the end

  auto it1 = lower_bound(v.begin(), v.end(), 37);
  cout << *it1 << endl;

  // we can get the index by subtracting v.begin()
  int it1_index = it1 - v.begin();
  // lower_bound(v.begin(), v.end(), 37) - v.begin();

  cout << it1_index << endl;



  // upper_bound(_first_iterator, _second_iterator, _val)
  // returns an iterator of the first element greater than  _val
  // if there is no element return iterator to the end

  auto it2 = upper_bound(v.begin(), v.end(), 37);
  cout << *it2 << endl;

  // we can get the index by subtracting v.begin()
  int it2_index = it2 - v.begin();
  // upper_bound(v.begin(), v.end(), 37) - v.begin();

  cout << it2_index << endl;



  // equal_range(_first_interator, _second_iterator, _val)
  // return a pair of iterators
  // first iterator is return value of lower_bound
  // second iterator is return value of upper_bound
  // if the value doen't present in the vector
  // first and second will be equal
  auto p1 = equal_range(v.begin(), v.end(), 37);
  cout << p1.first - v.begin() << " " << p1.second - v.begin() << endl;

  auto p2 = equal_range(v.begin(), v.end(), 9);
  cout << p2.first - v.begin() << " " << p2.second - v.begin() << endl;
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
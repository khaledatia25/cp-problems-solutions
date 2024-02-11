/*
    --------------------------------------------     ==============
    | Buggy Code Written By Khaled Waleed  ^_^ |     |   For Fun  |
    --------------------------------------------     ==============
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl '\n'

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define prec(n) cout << fixed << setprecision(n)
#define countbits(n) __builtin_popcount(n)

#define ll long long
#define int long long
#define OO (ll)1e18
#define oo (ll)1e9
#define angle(a) (atan2((a).imag(), (a).real()))

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_map =
    tree<T, map<T, F>, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_multimap = tree<T, map<T, F>, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &i : v) os << i << " ";
    os << '\n';
    return os;
}
using ld = long double;

void fileInput(/*Hello World*/);

typedef complex<double> point;

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll mod = 1e9 + 7;
// const ll mod = 998244353;
// const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 1e6 + 9;

class Solution {
   public:
    int cherryPickup(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dp[rows][cols][cols];
        // r -> current row for both of the robots
        // c1 -> currnet col for robot 1
        // c2 -> current col for robot 2
        memset(dp, 0, sizeof dp);
        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
        int ans = 0;
        int dy[] = {1, 0, -1};
        for (int r = 1; r < rows; r++) {
            for (int c1 = 0; c1 < cols; c1++) {
                for (int c2 = 0; c2 < cols; c2++) {
                    if (c1 > r || c2 < cols - r - 1 || c1 > c2) continue;
                    int &ret = dp[r][c1][c2];
                    ret = dp[r - 1][c1][c2];
                    for (int i = 0; i < 3; i++) {
                        int y1 = c1 + dy[i];
                        if (y1 < 0 || y1 >= cols) continue;
                        for (int j = 0; j < 3; j++) {
                            int y2 = c2 + dy[j];
                            if (y2 < 0 || y2 >= cols) continue;
                            ret = max(ret, dp[r - 1][y1][y2]);
                        }
                    }
                    if (c1 != c2)
                        ret += grid[r][c2] + grid[r][c1];
                    else
                        ret += grid[r][c1];
                    ans = max(ans, ret);
                }
            }
        }
        return ans;
    }
};

void init() {
}

void freePalestine(int tc) {
}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    init();
    int t = 1;
    //    cin >> t;
    int tc = 1;
    while (t--) {
        freePalestine(tc++);
    }

    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
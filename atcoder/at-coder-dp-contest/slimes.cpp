/*
    Buggy Code Written By Khaled Waleed  ^_^
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
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_map = tree<T, map<T, F>, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_multimap = tree<T, map<T, F>, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T>
using max_heap = priority_queue<T>;

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
const ll N = 1e4 + 9;

class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        bool isP[n][n];  // isP[l][r] is true if substring from l to r is palindrome
        for (int i = 0; i < n; i++) isP[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < n - len + 1; l++) {
                int r = l + len - 1;
                if (l == r - 1) {
                    isP[l][r] = s[l] == s[r];
                } else
                    isP[l][r] = isP[l + 1][r - 1] && s[l] == s[r];
            }
        }

        int dp[n][n];
        // dp[l][r] is number of palindrome substrings from l..r
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < n - len + 1; l++) {
                int r = l + len - 1;
                dp[l][r] += isP[l][r] + dp[l + 1][r] + dp[l][r - 1] - (l == r - 1 ? 0 : dp[l + 1][r - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

void init() {}

void elmtarshm(int tc) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &u : v) cin >> u;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<int> pre = v;
    for (int i = 1; i < n; i++) pre[i] += pre[i - 1];

    function<int(int, int)> get = [&](int L, int R) -> int {
        return pre[R] - (L ? pre[L - 1] : 0);
    };
    // dp[l][r] is the minimum cost to merge range from l to r
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = OO;
            for (int j = l; j < r; j++) {
                dp[l][r] = min(dp[l][r], dp[l][j] + dp[j + 1][r] + get(l, r));
            }
        }
    }
    cout << dp[0][n - 1] << endl;
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
        elmtarshm(tc++);
    }

    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
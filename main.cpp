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
const ll N = 4e2 + 9;

int soll() {
    int n, max_weight;
    cin >> n >> max_weight;
    vector<int> weights(n + 1), values(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weights[i] >> values[i];
    }
    vector<int> dp(max_weight + 1);
    // dp[w] is the max value can be obtained now if the available weight is w
    for (int i = 1; i <= n; i++) {
        vector<int> new_dp(max_weight + 1);  // to store the new answers
        for (int w = 0; w <= max_weight; w++) {
            new_dp[w] = dp[w];
            if (w >= weights[i]) {
                new_dp[w] = max(new_dp[w], dp[w - weights[i]] + values[i]);
            }
            // swap the old with the new
            swap(dp, new_dp);
        }
    }
    cout << dp[max_weight] << endl;
}

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int sols(int n) {
    bitset<61> num(n);
    int dp[62][100][2];
    // dp[i][sum][0] count of suffixes that can be formed starting from index i, whose digits add up to sum
    // dp[i][sum][1] coutn of suffixes that can be formed starting from index i, whose digits add up to sum such that the formed suffix is not greater than corresponding suffix in input string
    memset(dp, 0, sizeof dp);
    string s = num.to_string();
    dp[0][0][1] = 1;
    for (int i = 0; i < s.length(); i++) {
        for (int sum = 0; sum <= s.length(); sum++) {
            for (int cant : {0, 1}) {
                if (!cant) {
                    for (int d = 0; d < 2; d++) {
                        dp[i + 1][sum + d][cant] += dp[i][sum][cant];
                    }
                } else {
                    for (int d = 0; d < s[i] - '0'; d++) {
                        dp[i + 1][sum + d][0] += dp[i][sum][cant];
                    }
                    dp[i + 1][sum + s[i] - '0'][1] += dp[i][sum][cant];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= s.size(); i++) {
        if (is_prime(i)) ans += dp[s.size()][i][1] + dp[s.size()][i][0];
    }
    return ans;
}
int sol(int n) {
    bitset<61> bt(n);
    string a = bt.to_string();
    n = a.size();
    int dp[100][2][100];
    memset(dp, 0, sizeof dp);
    dp[n][0][0] = dp[n][1][0] = 1;
    for (int i = n - 1; ~i; i--) {
        for (int sum = 0; sum <= n; sum++) {
            for (int j = 0; j < 2; j++)
                dp[i][0][sum] += dp[i + 1][0][sum - j];
            for (int j = 0; j <= a[i] - '0'; j++)
                dp[i][1][sum] += dp[i + 1][(a[i] - '0' == j)][sum - j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (is_prime(i)) ans += dp[0][1][i];
    }
    return ans;
}

void init() {
}

void freePalestine(int tc) {
    int n;
    cin >> n;
    int low = 0, high = 1e18, mid, ans;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (sol(mid) >= n) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}
/*
e -> b or d
o -> a or d
*/
int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    init();
    int t = 1;
    cin >> t;
    int tc = 1;
    while (t--) {
        freePalestine(tc++);
    }

    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
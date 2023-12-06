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
const ll N = 3e5 + 9;
vector<pair<int, int>> g[N];
void init() {
}

void freePalestine(int tc) {
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[max(x, y)].push_back({x, y});
    }
    mp[0].push_back({0, 0});
    for (auto &[_, v] : mp) {
        sort(all(v), [&](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
    }
    function<int(pair<int, int>, pair<int, int>)> dist = [&](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    auto dp = vector<vector<int>>(mp.size() + 1, vector<int>(2, OO));
    int prev = 0, level = 0;
    dp[0][0] = dp[0][1] = 0;
    for (auto &[_, v] : mp) {
        level++;
        auto a = v[0];
        auto b = v.back();
        auto prev_a = mp[prev][0];
        auto prev_b = mp[prev].back();
        // 0 -> a
        // 1 -> b
        int d = dist(a, b);
        dp[level][0] = min(dp[level][0], dp[level- 1][0] + d + dist(prev_a, b));
        dp[level][0] = min(dp[level][0], dp[level- 1][1] + d + dist(prev_b, b));
        dp[level][1] = min(dp[level][1], dp[level- 1][0] + d + dist(prev_a, a));
        dp[level][1] = min(dp[level][1], dp[level- 1][1] + d + dist(prev_b, a));
        prev = _;
    }
    cout << min(dp[level][0], dp[level][1]) << endl;
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
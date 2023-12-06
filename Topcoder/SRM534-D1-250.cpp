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
const ll N = 1e6 + 9;
class EllysCheckers {
   public:
    int dp[1 << 20];
    int bit(int num, int i) {
        return (num >> i) & 1;
    }
    int n;
    bool rec(int mask) {
        if (bit(mask, n - 1))
            return rec(mask ^ (1 << n - 1));
        if (!mask) return 0;
        int &ret = dp[mask];
        if (~ret) return ret;
        ret = 0;
        for (int i = 0; i < n && !ret; i++) {
            if (!bit(mask, i)) continue;
            if (!bit(mask, i + 1)) {
                int temp = mask ^ (1 << (i + 1)) ^ (1 << i);
                ret |= !rec(temp);
            }
            if (i + 3 < n && bit(mask, i + 1) && bit(mask, i + 1) && !bit(mask, i + 3)) {
                int temp = mask ^ (1 << (i + 3)) ^ (1 << i);
                ret |= !rec(temp);
            }
        }
        return ret;
    }
    string getWinner(string a) {
        n = a.size();
        memset(dp, -1, sizeof dp);
        int mask = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 'o') mask |= (1 << i);
        }
        bool b = rec(mask);
        return (b ? "YES" : "NO");
    }
};

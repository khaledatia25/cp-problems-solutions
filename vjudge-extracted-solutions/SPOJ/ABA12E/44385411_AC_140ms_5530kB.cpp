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
void fileInput(/*Hello World*/);
typedef complex<double> point;
const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const ll mod = 1e9 + 7;
// const ll mod = 9982443 53;
const int sz = 2e5 + 1;
const int K = 500 + 9;
const ll N = 1e7 + 9;

int power(int base, int n) {
    if (!n)
        return 1ll;
    return ((n & 1) ? base : 1ll) * power(base * base, n >> 1);
}

vector<int> v;
vector<int> pre;
int pred(int sum) {
    int cnt = 0;
    for (int i = 0; i < pre.size(); i++) {
        int lo = i, hi = pre.size() - 1;
        int res = -1;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            int pr = i ? pre[mid] - pre[i - 1] : pre[mid];
            if (pr <= sum) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (~res) {
            cnt += res - i + 1;
        }
    }
    return cnt;
}

void init() {
}
void elmtarshm(int tc) {
    int n, k;
    cin >> n >> k;
    v = vector<int>(n);
    for (int &i : v)
        cin >> i;
    pre = v;
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1];

    int ans = -1;
    int lo = 0, hi = 1e15;
    while (lo <= hi) {
        int mid = lo + hi >> 1;
        if (pred(mid) >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    init();
    int t = 1;
    // cin >> t;
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
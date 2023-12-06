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
#define countbits(n) __builtin_popcountll(n)

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
    for (auto &i : v)
        is >> i;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &i : v)
        os << i << " ";
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
const ll N = 1 << 17;

int n, arr[N];
vector<int> t[N << 1];
void build(int x = 0, int lx = 0, int rx = n - 1) {
    if (lx == rx) {
        t[x].push_back(arr[lx]);
        return;
    }
    int left = x * 2 + 1, right = x * 2 + 2, mid = lx + rx >> 1;
    build(left, lx, mid);
    build(right, mid + 1, rx);
    merge(t[left].begin(), t[left].end(), t[right].begin(), t[right].end(), inserter(t[x], t[x].begin()));
}

int query(int qs, int qe, int val, int x = 0, int lx = 0, int rx = n - 1) {
    if (lx > qe or rx < qs) return 0;
    if (lx >= qs and rx <= qe) return lower_bound(all(t[x]), val) - t[x].begin();
    int left = x * 2 + 1, right = x * 2 + 2, mid = lx + rx >> 1;
    return query(qs, qe, val, left, lx, mid) + query(qs, qe, val, right, mid + 1, rx);
}
int BS(int qs, int qe, int k) {
    int st = -1e9, en = 1e9;
    while (st < en) {
        int mid = st + (en - st) / 2;
        if (query(qs, qe, mid) >= k) {
            en = mid;
        } else {
            st = mid + 1;
        }
    }
    return st;
}

void init() {
}

void elmtarshm(int tc) {
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build();
    while (m--) {
        int qs, qe, val;
        cin >> qs >> qe >> val;
        cout << BS(--qs, --qe, val) - 1 << endl;
    }
}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    // fileInput();
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
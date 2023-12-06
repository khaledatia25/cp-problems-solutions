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

void init() {
}
struct node {
    int pre, suf, mx, sum;
    node() : pre(INT_MIN), suf(INT_MIN), mx(INT_MIN), sum(0) {}
};
node merge(node l, node r) {
    node n;

    n.pre = max(l.pre, l.sum + r.pre);
    n.suf = max(r.suf, r.sum + l.suf),
    n.mx = max({l.mx, r.mx, l.suf + r.pre}),
    n.sum = l.sum + r.sum;
    return n;
};
void freePalestine(int tc) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<node> v(n);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> b(l);
        cin >> b;
        v[i].sum = accumulate(all(b), 0);
        int p = 0;
        for (int j = 0; j < l; j++) {
            p += b[j];
            v[i].pre = max(v[i].pre, p);
        }
        p = 0;
        for (int j = l - 1; ~j; j--) {
            p += b[j];
            v[i].suf = max(v[i].suf, p);
        }
        p = 0;
        for (int j = 0; j < l; j++) {
            p += b[j];
            v[i].mx = max(p, v[i].mx);
            if (p < 0) p = 0;
        }
    }

    node ans;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        ans = merge(ans, v[x - 1]);
    }
    cout << ans.mx << endl;
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
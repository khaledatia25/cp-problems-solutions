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
const ll N = 1e4 + 9;
double dist(double a, double b, double c, double d) {
    a -= c;
    b -= d;
    return sqrt(a * a + b * b);
}
pair<double, double> p, a, b;
const double eps = 1e-6;
bool pred(double r) {
    int s = 0, d = 0;
    if (dist(a.first, a.second, p.first, p.second) <= r)
        d = 1;
    else if (dist(b.first, b.second, p.first, p.second) <= r)
        d = 2;
    if (dist(a.first, a.second, 0, 0) <= r)
        s = 1;
    else if (dist(b.first, b.second, 0, 0) <= r)
        s = 2;
    if (d != s && s) {
        if (fabs(dist(a.first, a.second, b.first, b.second) - 2.0 * r) < eps)
            return 1;
        else
            return false;
    }

    // cout << s << space << d << endl;
    return s && d;
}
void get(pair<double, double> &p) {
    cin >> p.first >> p.second;
}

void init() {}
void elmtarshm(int tc) {
    get(p);
    get(a);
    get(b); 
    double dist0a = dist(0, 0, a.first, a.second);
    double dist0b = dist(0, 0, b.first, b.second);
    double distsa = dist(p.first, p.second, a.first, a.second);
    double distsb = dist(p.first, p.second, b.first, b.second);
    prec(9);
    if (dist0a < dist0b && distsa < distsb) {
        cout << max(dist0a, distsa) << endl;
    } else if (dist0b < dist0a && distsb < distsa) {
        cout << max(dist0b, distsb) << endl;
    } else {
        double r = dist(a.first, a.second, b.first, b.second) / 2;
        cout << max({r, min(dist0a, dist0b), min(distsa, distsb)}) << endl;
    }
    //     double st = 0, nd = 1e6;
    //     for (int i = 0; i < 300; i++) {
    //         double mid = (st + nd) / 2;
    //         if (pred(mid)) {
    //             nd = mid;
    //         } else {
    //             st = mid;
    //         }
    //     }
    //     cout << nd << endl;
}

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
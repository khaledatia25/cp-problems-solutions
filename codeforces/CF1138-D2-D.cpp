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

void init() {
}

void freePalestine(int tc) {
    string s, t;
    cin >> s >> t;
    int oneS = 0, zeroS = 0;
    int oneT = 0, zeroT = 0;
    for (char c : s) oneS += (c == '1'), zeroS += (c == '0');
    for (char c : t) oneT += (c == '1'), zeroT += (c == '0');
    if (oneS < oneT || zeroS < zeroT) {
        cout << s << endl;
        return;
    }
    vector<int> longestPrefix(t.size(), 0);
    for (int i = 1, k = 0; i < t.size(); i++) {
        while (k && t[k] != t[i]) k = longestPrefix[k - 1];
        if (t[k] == t[i])
            longestPrefix[i] = ++k;
        else
            longestPrefix[i] = k;
    }
    cout << t;
    oneS -= oneT;
    zeroS -= zeroT;
    for (int i = 0; i < longestPrefix.back(); i++) {
        oneT -= (t[i] == '1');
        zeroT -= (t[i] == '0');
    }
    while (oneS >= oneT && zeroS >= zeroT) {
        for (int i = longestPrefix.back(); i < t.size(); i++) cout << t[i];
        oneS -= oneT;
        zeroS -= zeroT;
    }
    while (oneS--) cout << '1';
    while (zeroS--) cout << '0';
    cout << endl;
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
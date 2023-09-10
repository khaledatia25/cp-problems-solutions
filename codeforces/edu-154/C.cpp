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

const int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 },
dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const ll mod = 1e9 + 7;
// const ll mod = 998244353;
// const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 1e4 + 9;

void init() {}

void elmtarshm(int tc) {
    string s;
    cin >> s;
    int n = s.size();
    int cur = 0, prev = 0, ordered = 1, added = 0, removed = 0, to_be_removed = 0;
    bool valid = true;
    for (int i = 0; i < n;i++) {
        if (cur < 0) {
            valid = false;
            break;
        }
        if (s[i] == '+') {
            cur++;
            added++;
            continue;
        }
        if (s[i] == '-') {
            cur--;
            if (added) added--;
            else removed++;
            continue;
        }
        if (s[i] == '1') {
            if (cur <= 1)continue;
            if (removed < to_be_removed) {
                if (!ordered) {
                    valid = false;
                    break;
                }
            }
            added = 0;
            removed = 0;
            to_be_removed = 0;
            prev = cur;
            ordered = 1;
            continue;
        }
        if (s[i] == '0') {
            if (cur <= 1) {
                valid = false;
                break;
            }
            if (added == 0 && ordered) {
                valid = false;
                break;
            }
            if (!ordered && removed < to_be_removed) {
                to_be_removed += added - removed;
            }
            else {
                to_be_removed = 1;
            }
            added = 0;
            removed = 0;
            prev = cur;
            ordered = 0;
            continue;
        }

    }
    cout << (valid ? "YES" : "NO") << endl;
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
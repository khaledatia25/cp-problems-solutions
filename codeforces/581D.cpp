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
    array<int, 2>a, b, c;
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    cin >> c[0] >> c[1];
    char A = 'A', B = 'B', C = 'C';
    for (int a7a = 0; a7a < 3; a7a++) {
        for (int i : {0, 1}) {
            for (int j : {0, 1}) {
                for (int k : {0, 1}) {
                    if (a[i] == b[j] + c[k] && b[!j] == c[!k] && a[i] == a[!i] + c[!k]) {
                        cout << a[i] << endl;
                        for (int l = 0; l < a[!i]; l++) {
                            cout << string(a[i], A) << endl;;
                        }
                        string line;
                        for (int l = 0; l < b[j]; l++) {
                            line.push_back(B);
                        }
                        for (int l = 0; l < c[k]; l++) {
                            line.push_back(C);
                        }
                        for (int l = 0; l < c[!k]; l++) {
                            cout << line << endl;
                        }

                        return;
                    }
                    if (a[i] == b[j] && b[j] == c[k] && a[i] == a[!i] + b[!j] + c[!k]) {
                        cout << a[i] << endl;
                        for (int l = 0; l < a[!i]; l++) {
                            cout << string(a[i], A) << endl;
                        }
                        for (int l = 0; l < b[!j]; l++) {
                            cout << string(b[j], B) << endl;
                        }
                        for (int l = 0; l < c[!k]; l++) {
                            cout << string(c[k], C) << endl;;
                        }
                        return;
                    }
                }
            }
        }
        if (a7a == 0) {
            swap(a, b);
            swap(A, B);
        }
        else {
            swap(a, c);
            swap(A, C);
        }
    }
    cout << -1 << endl;
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
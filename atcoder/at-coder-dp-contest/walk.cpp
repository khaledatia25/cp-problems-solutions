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

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll mod = 1e9 + 7;
// const ll mod = 998244353;
// const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 1e4 + 9;
class MatrixExponentiation {
   public:
    const static ll MOD = 1e9 + 7;
    static vector<vector<ll>> matMul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
        ll d1 = a.size();
        ll d2 = b.size();
        ll d3 = b[0].size();

        vector<vector<ll>> ret(d1, vector<ll>(d3));
        for (int i = 0; i < d1; i++) {
            for (int j = 0; j < d2; j++) {
                for (int k = 0; k < d3; k++) {
                    ret[i][k] = (ret[i][k] % MOD + 1ll * a[i][j] * b[j][k]) % MOD;
                }
            }
        }
        return ret;
    }
    static vector<vector<ll>> power(vector<vector<ll>> &b, ll p) {
        ll d = b.size();
        vector<vector<ll>> ret(d, vector<ll>(d));
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                ret[i][j] = (i == j);
            }
        }
        while (p) {
            if (p & 1)
                ret = matMul(ret, b);
            b = matMul(b, b);
            p >>= 1;
        }
        return ret;
    }
};
void init() {}

void elmtarshm(int tc) {
    int n, m, k;
    cin >> n >> k;
    MatrixExponentiation M;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    adj = M.power(adj, k);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans % mod + adj[i][j] % mod) % mod;
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
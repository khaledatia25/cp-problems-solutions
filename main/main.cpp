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

int n;
extern struct node *empty_node;
struct node {
    int sum;
    node *left, *right;
    node() : left(this), right(this), sum(0) {
    }
    node(int val, node *left = empty_node, node *right = empty_node) : sum(val), left(left), right(right) {
    }
};
node *empty_node = new node();
node *roots[N];
void init() {
}
node *insert(int val, node *cur, int ns = -1e9, int ne = 1e9) {
    if (val < ns or val > ne) return cur;
    if (ns == ne) {
        return new node(cur->sum + 1);
    }
    int mid = ns + (ne - ns) / 2;
    node *lf = insert(val, cur->left, ns, mid);
    node *rt = insert(val, cur->right, mid + 1, ne);
    return new node(lf->sum + rt->sum, lf, rt);
}
int query(int k, node *en, node *stm1, int ns = -1e9, int ne = 1e9) {
    if (ns == ne) return ns;
    int lfsz = en->left->sum - stm1->left->sum;
    int mid = ns + (ne - ns) / 2;
    if (k <= lfsz) return query(k, en->left, stm1->left, ns, mid);
    return query(k - lfsz, en->right, stm1->right, mid + 1, ne);
}
void elmtarshm(int tc) {
    roots[0] = empty_node;
    int m, xx;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> xx;
        roots[i] = insert(xx, roots[i - 1]);
    }
    int qs, qe, k;
    while (m--) {
        cin >> qs >> qe >> k;
        cout << query(k, roots[qe], roots[qs - 1]) << endl;
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
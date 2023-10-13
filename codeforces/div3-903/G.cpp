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
const ll N = 1e4 + 9;
struct node {
    vector<int> pre, suf;
    bool marked;
    bool palindrome;
    int lazy;
    node() {
        marked = 0, palindrome = 0, lazy = 0;
    }
    node(int x) {
        pre.push_back(x);
        suf.push_back(x);
        marked = 0, palindrome = 0, lazy = 0;
    }
};
struct segaya {
    int size;
    vector<node> tree;
    node NUTRL = node();
    void init(int n) {
        size = n + 5;
        while (countbits(size) != 1)
            ++size;
        tree = vector<node>(2 * size, NUTRL);
    }
    node single(int number) {
        return node(number);
    }
    node merge(node &l, node &r) {
        node ret = node();
        ret.pre = l.pre;
        if (ret.pre.size() < 2) {
            for (int i = 0; i < 2 - ret.pre.size(); i++) {
                if (i < r.pre.size()) ret.pre.push_back(r.pre[i]);
            }
        }
        ret.suf = r.suf;
        if (ret.suf.size() < 2) {
            for (int i = 0; i < 2 - ret.suf.size(); i++) {
                if (i < l.suf.size()) ret.suf.push_back(l.suf[i]);
            }
        }
        ret.palindrome = 0;
        ret.palindrome = l.palindrome | r.palindrome;
        if (l.suf.size() && r.pre.size()) {
            ret.palindrome |= (l.suf.back() == r.pre.front());
            ret.palindrome |= (l.suf.front() == r.pre.back());
            ret.palindrome |= (l.suf.front() == r.pre.front());
        }
        return ret;
    }
    void build(vector<int> &numbers, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < numbers.size()) {
                tree[x] = single(numbers[lx]);
            }
            return;
        }
        int mid = lx + rx >> 1;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void build(vector<int> &numbers) {
        build(numbers, 0, 0, size);
    }

    void push(int x, int lx, int rx) {
        if (!tree[x].marked)
            return;
        for (int &i : tree[x].pre) {
            i += tree[x].lazy;
            i %= 26;
        }
        for (int &i : tree[x].suf) {
            i += tree[x].lazy;
            i %= 26;
        }
        if (rx - lx > 1) {
            tree[2 * x + 1].lazy += tree[x].lazy;
            tree[2 * x + 1].marked = 1;

            tree[2 * x + 2].lazy += tree[x].lazy;
            tree[2 * x + 2].marked = 1;
        }
        tree[x].lazy = 0;
        tree[x].marked = 0;
    }

    void update(int l, int r, int val, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || l >= rx) {
            return;
        }
        if (lx >= l && rx <= r) {
            tree[x].lazy += val;
            tree[x].marked = true;
            push(x, lx, rx);
            return;
        }
        int mid = lx + rx >> 1;
        update(l, r, val, 2 * x + 1, lx, mid);
        update(l, r, val, 2 * x + 2, mid, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int l, int r, int val) {
        update(l, r, val, 0, 0, size);
    }

    node get(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || l >= rx) {
            return NUTRL;
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int mid = lx + rx >> 1;
        auto L = get(l, r, 2 * x + 1, lx, mid);
        auto R = get(l, r, 2 * x + 2, mid, rx);
        return merge(L, R);
    }
    node get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
};
void init() {}

void elmtarshm(int tc) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i] - 'a';
    }
    segaya shagra;
    shagra.init(n);
    shagra.build(v);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            shagra.update(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << (shagra.get(l, r).palindrome ? "NO" : "YES") << endl;
        }
    }
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
/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
const int sz = 3e5 + 1;
const int K = 500 + 9;
const ll N = 1e7 + 9;

int power(int base, int n)
{
    if (!n)
        return 1ll;
    return ((n & 1) ? base : 1ll) * power(base * base, n >> 1);
}

struct node
{
    int maxSum, prefix, sufix, sum;
};
struct segaya
{
    int size = 1;
    vector<node> tree;
    node nutral = {-oo, -oo, -oo, -oo};

    node single(int number)
    {
        return {number, number, number, number};
    }

    node merge(node &l, node &r)
    {
        return {
            max({l.maxSum, r.maxSum, l.sufix + r.prefix}),
            max(l.prefix, l.sum + r.prefix),
            max(r.sufix, r.sum + l.sufix),
            l.sum + r.sum};
    }

    void init(int n)
    {
        size = n;
        while (countbits(size) != 1)
            size++;

        tree.assign(size * 2, nutral);
    }

    void build(vector<int> &numbers, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < numbers.size())
            {

                tree[x] = single(numbers[lx]);
            }
            return;
        }
        int mid = (lx + rx) / 2;
        int left = 2 * x + 1;
        int right = 2 * x + 2;
        build(numbers, left, lx, mid);
        build(numbers, right, mid, rx);
        tree[x] = merge(tree[left], tree[right]);
    }

    void build(vector<int> &numbers)
    {
        build(numbers, 0, 0, size);
    }

    void update(int i, int number, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = single(number);
            return;
        }
        int mid = (lx + rx) / 2;
        int right = 2 * x + 2;
        int left = 2 * x + 1;
        if (i < mid)
        {
            update(i, number, left, lx, mid);
        }
        else
        {
            update(i, number, right, mid, rx);
        }
        tree[x] = merge(tree[left], tree[right]);
    }
    void update(int i, int number)
    {
        update(i, number, 0, 0, size);
    }

    node get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
        {
            return nutral;
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        int mid = (lx + rx) / 2;
        int left = 2 * x + 1;
        int right = 2 * x + 2;
        node leftSeg = get(l, r, left, lx, mid);
        node rightSeg = get(l, r, right, mid, rx);
        return merge(leftSeg, rightSeg);
    }

    node get(int l, int r)
    {
        return get(l, r, 0, 0, size);
    }
};

void init()
{
}
/*

*/

void elmtarshm(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    segaya shagra;
    shagra.init(n + 50);
    shagra.build(v);
    int m;
    cin >> m;
    while (m--)
    {
        int l, r, op;
        cin >> op;
        cin >> l >> r;
        if (op)
        {

            auto ans = shagra.get(l - 1, r).maxSum;
            cout << ans << endl;
        }
        else
        {
            shagra.update(l - 1, r);
        }
    }
}

int32_t main()
{
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    init();
    int t = 1;
    // cin >> t;
    int tc = 1;
    while (t--)
    {
        elmtarshm(tc++);
    }

    return 0;
}

void fileInput()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
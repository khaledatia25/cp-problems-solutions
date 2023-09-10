/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
#include <iostream>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl '\n'

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define stprec(n) cout << fixed << setprecision(n)
#define countbits(n) __builtin_popcount(n)

#define ll long long
#define int long long
#define OO (ll)1e18
#define oo (ll)1e9

using namespace std;
void fileInput(/*Hello World*/);

// const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
//           dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const ll mod = 1e9 + 7;
// const ll mod = 9982443 53;
const int sz = 3e5 + 1;
const ll N = 1e6 + 1;
bool isPrime[N];
struct segaya
{
    int size;
    vector<int> seg, lazy;
    vector<bool> marked;
    int NUTRL = 0;
    void init(int n)
    {
        size = n + 5;
        while (countbits(size) != 1)
            ++size;
        seg = vector<int>(2 * size);
        lazy = vector<int>(2 * size, NUTRL);
        marked = vector<bool>(2 * size, 0);
    }

    void build(vector<int> &numbers, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < numbers.size())
            {
                seg[x] = numbers[lx];
            }
            return;
        }
        int mid = lx + rx >> 1;
        build(numbers, 2 * x + 1, lx, mid);
        build(numbers, 2 * x + 2, mid, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void build(vector<int> &numbers)
    {
        build(numbers, 0, 0, size);
    }

    void push(int x, int lx, int rx)
    {
        if (!marked[x])
            return;
        if (lazy[x] & 1)
            seg[x] = (rx - lx) - seg[x];
        if (rx - lx > 1)
        {
            lazy[2 * x + 1] += lazy[x];
            marked[2 * x + 1] = 1;

            lazy[2 * x + 2] += lazy[x];
            marked[2 * x + 2] = 1;
        }
        lazy[x] = 0;
        marked[x] = 0;
    }

    void update(int l, int r, int val, int x, int lx, int rx)
    {
        push(x, lx, rx);
        if (lx >= r || l >= rx)
        {
            return;
        }
        if (lx >= l && rx <= r)
        {
            lazy[x] += val;
            marked[x] = 1;
            push(x, lx, rx);
            return;
        }
        int mid = lx + rx >> 1;
        update(l, r, val, 2 * x + 1, lx, mid);
        update(l, r, val, 2 * x + 2, mid, rx);
        seg[x] = (seg[2 * x + 1] + seg[2 * x + 2]);
    }

    void update(int l, int r, int val)
    {
        update(l, r, val, 0, 0, size);
    }

    int get(int l, int r, int x, int lx, int rx)
    {
        push(x, lx, rx);
        if (lx >= r || l >= rx)
        {
            return NUTRL;
        }
        if (lx >= l && rx <= r)
        {

            return seg[x];
        }
        int mid = lx + rx >> 1;
        auto L = get(l, r, 2 * x + 1, lx, mid);
        auto R = get(l, r, 2 * x + 2, mid, rx);
        return (L + R);
    }
    int get(int l, int r)
    {
        return get(l, r, 0, 0, size);
    }
};

void init()
{
}
void elmtarshm(int tc)
{
    int n, q;
    cin >> n >> q;
    segaya shagra;
    shagra.init(n);
    while (q--)
    {
        int op;
        cin >> op;
        if (op)
        {
            int l, r;
            cin >> l >> r;
            cout << shagra.get(l - 1, r) << endl;
        }
        else
        {
            int l, r, v;
            cin >> l >> r;
            shagra.update(l - 1, r, 1);
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
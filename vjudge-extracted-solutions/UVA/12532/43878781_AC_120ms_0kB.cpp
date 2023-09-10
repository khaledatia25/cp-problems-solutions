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

#define ll long long
#define int long long
#define OO (ll)1e18
#define oo (ll)1e9

using namespace std;
void fileInput(/*Hello World*/);

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const ll mod = 1e9 + 7;
// const ll mod = 9982443 53;
const int sz = 3e5 + 1;
const ll N = 1e5 + 1;
int modulas;
struct node
{
    int sign;
};
struct segTree
{
    int size = 1;
    vector<node> tree;
    node nutral = {1};

    node single(int number)
    {
        if (!number)
        {
            return {0};
        }
        if (number < 0)
            return {-1};

        return {1};
    }

    node merge(node &l, node &r)
    {
        return {l.sign * r.sign};
    }

    void init(int n)
    {
        while (size < n)
            size *= 2;

        tree.assign(size * 2 + 9, nutral);
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
int32_t
main()
{
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    int n, m;
    while (cin >> n >> m)
    {
        segTree seg;
        seg.init(n);
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        seg.build(v);
        while (m--)
        {
            char op;
            cin >> op;
            if (op == 'C')
            {
                int i, val;
                cin >> i >> val;
                seg.update(i - 1, val);
            }
            else
            {
                int i, j;
                cin >> i >> j;
                int ans = seg.get(i - 1, j).sign;
                if (ans)
                {
                    cout << (ans < 0 ? '-' : '+');
                }
                else
                {
                    cout << 0;
                }
            }
        }
        cout << endl;
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

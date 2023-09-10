/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl '\n'

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

#define ll long long
#define int long long

#define OO (ll)3e18 + 5
#define oo (ll)1e9

using namespace std;
void fileInput(/*Hello World*/);

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const int sz = 2e5 + 9;
const ll N = 1e7 + 9;

ll mod = 1e9 + 7;

int solve(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    map<pair<int, int>, bool> vis;
    queue<pair<int, int>> qu;
    qu.push({jug1Capacity, jug2Capacity});
    queue<int> depth;
    depth.push(0);
    vis[{jug1Capacity, jug2Capacity}] = 1;
    while (!qu.empty())
    {
        auto cur = qu.front();
        int d = depth.front();
        depth.pop();
        qu.pop();
        pair<int, int> p12, p21;

        if (cur.first > jug2Capacity - cur.second)
        {
            p12.first = cur.first - (jug2Capacity - cur.second);
            p12.second = jug2Capacity;
        }
        else
        {
            p12.first = 0;
            p12.second = cur.second + cur.first;
        }
        if (cur.second > jug1Capacity - cur.first)
        {
            p21.second = cur.second - (jug1Capacity - cur.first);
            p21.first = jug1Capacity;
        }
        else
        {
            p21.second = 0;
            p21.first = cur.first + cur.second;
        }
        pair<int, int> arr[] = {
            {jug1Capacity, cur.second},
            {cur.first, jug2Capacity},
            {0, cur.second},
            {cur.first, 0},
            p12,
            p21};

        for (auto i : arr)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                qu.push(i);
                depth.push(d + 1);
                if (i.first == targetCapacity || i.second == targetCapacity)
                {
                    return d + 1;
                }
            }
        }
    }

    return -1;
}
int32_t main()
{
    // fast input
    KHALED_WALEED_ATTIA

    // handle file input
    fileInput();
    int n, m, sum = 0;
    // solution function
    function<void(int)> sol;
    const int lmt = 1ll * 1e9;
    sol = [&](int test) -> void
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < c && b < c)
        {
            cout << -1 << endl;
            return;
        }
        cout << solve(a, b, c) << endl;
    };

    // tests
    int t = 1;
    cin >> t;

    // looooop
    int test = 1;
    while (t--)
    {

        sol(test++);
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
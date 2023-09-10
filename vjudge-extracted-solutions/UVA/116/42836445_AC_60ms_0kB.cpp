/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long long
#define int long long
#define OO (ll)1e18
#define oo (ll)1e9
using namespace std;
void fileInput();

int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};

const ll mod = 1e9 + 7;
const int sz = 2e5 + 9;

const ll N = 1e7 + 9;
vector<vector<int>> memo;
vector<vector<bool>> vis;
vector<vector<int>> grid;
int n, m;
int dp(int i, int j)
{
    if (j == m)
    {
        return grid[i][j];
    }

    int &ret = memo[i][j];
    if (vis[i][j])
        return ret;
    vis[i][j] = 1;

    int ch1 = dp(i, j + 1);

    int ch2 = 0;
    if (i + 1 <= n)
        ch2 = dp(i + 1, j + 1);
    else
        ch2 = dp(1, j + 1);

    int ch3 = 0;
    if (i - 1 > 0)
        ch3 = dp(i - 1, j + 1);
    else
        ch3 = dp(n, j + 1);

    return ret = grid[i][j] + min({ch1, ch2, ch3});
}

void dp_print(int i, int j)
{
    if (j == m)
    {
        cout << i << endl;
        return;
    }

    int ch1 = dp(i, j + 1);

    int ch2 = 0;
    int row[3] = {i, 10000, 10000};
    if (i + 1 <= n)
        ch2 = dp(i + 1, j + 1), row[1] = i + 1;
    else
        ch2 = dp(1, j + 1), row[1] = 1;

    int ch3 = 0;
    if (i - 1 > 0)
        ch3 = dp(i - 1, j + 1), row[2] = i - 1;
    else
        ch3 = dp(n, j + 1), row[2] = n;

    int optimal = min({ch1, ch2, ch3});
    int ch[3] = {ch1, ch2, ch3};

    int mn_i = n;

    for (int i = 0; i < 3; i++)
    {
        if (ch[i] == optimal)
        {
            mn_i = min(mn_i, row[i]);
        }
    }
    cout << i << space;
    dp_print(mn_i, j + 1);

    return;
}

int32_t main()
{
    // fast input
    KHALED_WALEED_ATTIA

    // handle file input
    fileInput();

    // solution function
    function<void(int)> sol;
    sol = [&](int test) -> void
    {
        memo.assign(n + 9, vector<int>(m + 9, 0));
        vis.assign(n + 9, vector<bool>(m + 9, 0));
        grid.assign(n + 9, vector<int>(m + 9, 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int ans = dp(1, 1);
        int ii = 1;
        for (int i = 2; i <= n; i++)
        {
            if (dp(i, 1) < ans)
            {
                ans = dp(i, 1);
                ii = i;
            }
        }
        dp_print(ii, 1);
        cout << dp(ii, 1) << endl;
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 1;
    while (cin >> n >> m)
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
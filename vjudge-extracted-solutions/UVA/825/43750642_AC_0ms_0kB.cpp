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
const int sz = 2e5 + 9;
const ll N = 1e5 + 1;

int32_t main()
{
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    bool f = 0;
    int n, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cin.ignore();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        vector<vector<bool>> notSafe = vector<vector<bool>>(n + 1, vector<bool>(m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            string s;
            getline(cin, s);
            stringstream ss(s);
            int r, c;
            ss >> r;
            while (ss >> c)
            {
                notSafe[r][c] = 1;
            }
        }
        dp[n][m] = 1;
        for (int i = n; i > 0; i--)
        {
            for (int j = m; j > 0; j--)
            {
                if (i == n && j == m)
                {
                    dp[i][j] = 1;
                    continue;
                }

                if (i < n && !notSafe[i + 1][j])
                    dp[i][j] += dp[i + 1][j];
                if (j < m && !notSafe[i][j + 1])
                    dp[i][j] += dp[i][j + 1];
            }
        }

        if (f)
            cout << endl;
        f = 1;
        cout << dp[1][1] << endl;
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
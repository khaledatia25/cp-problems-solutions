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

/*
    Geometry Staff
*/

using namespace std;
void fileInput();

int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};

const ll mod = 1e9 + 7;
const int sz = 2e5 + 9;

const ll N = 1e7 + 9;

bool check(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int32_t main()
{
    // fast input
    KHALED_WALEED_ATTIA

    // handle file input
    fileInput();

    // solution function
    int m, n, x, y;

    function<void(int)> sol;
    string line1, line2;
    sol = [&](int test) -> void
    {
        if (test < 10)
            cout << " ";
        getline(cin, line2);
        vector<string> a, b;
        for (int i = 0; i < line1.size(); i++)
        {
            if (!isalnum(line1[i]))
                line1[i] = ' ';
        }
        for (int i = 0; i < line2.size(); i++)
        {
            if (!isalnum(line2[i]))
                line2[i] = ' ';
        }
        stringstream ss1(line1);
        string temp;
        while (ss1 >> temp)
            a.push_back(temp);
        stringstream ss2(line2);
        while (ss2 >> temp)
            b.push_back(temp);

        if (a.size() == 0 || b.size() == 0)
        {
            cout << test << ". Blank!" << endl;
            return;
        }
        int n = max(a.size(), b.size());
        int dp[a.size() + 1][b.size() + 1];
        memset(dp, 0, sizeof dp);
        for (int i = a.size() - 1; i >= 0; i--)
        {
            for (int j = b.size() - 1; j >= 0; j--)
            {
                int ch = 0;
                if (a[i] == b[j])
                    ch = 1 + dp[i + 1][j + 1];
                dp[i][j] = max({ch, dp[i + 1][j], dp[i][j + 1]});
            }
        }

        cout << test << ". Length of longest match: " << dp[0][0] << endl;
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 1;
    while (getline(cin, line1))
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
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
string s;
int n;

int dp(int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (i + 1 == j)
    {
        return (s[i] != s[j]);
    }
    int &ret = memo[i][j];
    if (~ret)
        return ret;

    int ch1 = 1e9;
    if (s[i] == s[j])
        ch1 = dp(i + 1, j - 1);

    int ch2 = 1 + dp(i + 1, j);
    int ch3 = 1 + dp(i, j - 1);

    return ret = min({ch1, ch2, ch3});
}

string ans1, ans2;
void dp_print(int i, int j)
{
    if (i == j)
    {
        ans1.push_back(s[i]);
        return;
    }
    if (i + 1 == j)
    {
        ans1.push_back(s[i]);
        ans2.push_back(s[i]);
        if (s[i] != s[j])
            ans1.push_back(s[j]);
        return;
    }

    int ch1 = 1e9;
    if (s[i] == s[j])
        ch1 = dp(i + 1, j - 1);

    int ch2 = 1 + dp(i + 1, j);
    int ch3 = 1 + dp(i, j - 1);

    int optimal = dp(i, j);

    if (optimal == ch1)
    {
        ans1.push_back(s[i]);
        ans2.push_back(s[i]);

        dp_print(i + 1, j - 1);
    }
    else if (optimal == ch2)
    {
        ans1.push_back(s[i]);
        ans2.push_back(s[i]);
        dp_print(i + 1, j);
    }
    else
    {
        ans1.push_back(s[j]);
        ans2.push_back(s[j]);
        dp_print(i, j - 1);
    }
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
        n = s.size();
        memo.assign(n + 9, vector<int>(n + 9, -1));

        cout << dp(0, n - 1) << space;
        ans1.clear();
        ans2.clear();
        dp_print(0, n - 1);
        reverse(all(ans2));
        cout << ans1 << ans2 << endl;
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 1;
    while (cin >> s)
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
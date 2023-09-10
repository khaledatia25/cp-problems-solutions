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
int dp(int i, int j)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        return 1;
    }

    int &ret = memo[i][j];
    if (~ret)
        return ret;

    int ch1, ch2, ch3;
    ch1 = ch2 = ch2 = 0;

    if (s[i] == s[j])
    {
        ch1 = 2 + dp(i + 1, j - 1);
    }
    ch2 = dp(i, j - 1);
    ch3 = dp(i + 1, j);

    return ret = max({ch1, ch2, ch3});
}

vector<vector<string>> memo2;

string dp_build(int i, int j)
{
    if (i > j)
    {
        return "";
    }
    if (i == j)
    {
        string sss;
        sss.push_back(s[i]);
        return sss;
    }
    string &ret = memo2[i][j];
    if (ret != "")
        return ret;

    int optimal = dp(i, j);

    int ch1, ch2, ch3;
    ch1 = ch2 = ch2 = 0;

    if (s[i] == s[j])
    {
        ch1 = 2 + dp(i + 1, j - 1);
    }
    ch2 = dp(i, j - 1);
    ch3 = dp(i + 1, j);

    if (optimal == ch1)
    {
        ret = s[i] + dp_build(i + 1, j - 1) + s[j];
    }

    if (optimal == ch2)
    {
        if (ret.size())
        {
            ret = min(ret, dp_build(i, j - 1));
        }
        else
        {
            ret = dp_build(i, j - 1);
        }
    }

    if (optimal == ch3)
    {
        if (ret.size())
        {
            ret = min(ret, dp_build(i + 1, j));
        }
        else
        {
            ret = dp_build(i + 1, j);
        }
    }

    return ret;
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
        memo.assign(s.size() + 9, vector<int>(s.size() + 9, -1));
        memo2.assign(s.size() + 9, vector<string>(s.size() + 9, ""));
        cout << dp_build(0, s.size() - 1) << endl;
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
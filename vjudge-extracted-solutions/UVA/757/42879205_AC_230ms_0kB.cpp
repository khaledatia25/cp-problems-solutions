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
int n;
vector<int> f, d, t;

int dp(int i, int h)
{
    if (h <= 0)
        return 0;
    if (i == n)
        return 0;

    int &ret = memo[i][h];
    if (~ret)
        return ret;
    ret = 0;
    int transition = i < n - 1 ? t[i] : 0;
    ret = dp(i + 1, h - transition);

    int sum = f[i];

    for (int j = 1; j <= h; j++)
    {
        ret = max(ret, sum + dp(i + 1, h - transition - j));
        sum += max(0LL, f[i] - j * d[i]);
    }

    return ret;
}

vector<int> ans;
void dp_build(int i, int h)
{

    if (i == n)
        return;

    int transition = i < n - 1 ? t[i] : 0;
    int sum = f[i];
    int cc = 0;
    int optimal = dp(i, h);
    for (int j = 1; j <= h; j++)
    {
        if (optimal == dp(i + 1, h - transition - j) + sum)
        {
            cc = j;
        }
        sum += max(0LL, f[i] - j * d[i]);
    }
    ans.push_back(cc * 5);
    dp_build(i + 1, h - transition - cc);
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
        int h;
        cin >> h;
        h *= 12;
        f.resize(n);
        d.resize(n);
        t.resize(n - 1);
        ans.clear();
        memo.assign(n + 9, vector<int>(h + 9, -1));
        for (int i = 0; i < n; i++)
            cin >> f[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        for (int i = 0; i < n - 1; i++)
            cin >> t[i];

        dp(0, h);
        dp_build(0, h);
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
        {
            cout << ", " << ans[i];
        }
        cout << endl;
        cout << "Number of fish expected: " << dp(0, h) << endl;
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 1;
    while (cin >> n, n)
    {
        if (test > 1)
            cout << endl;
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
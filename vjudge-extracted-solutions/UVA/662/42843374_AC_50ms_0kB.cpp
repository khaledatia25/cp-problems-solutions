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
vector<int> v;

int n, k;
int dp(int i, int rem)
{
    if (rem < 0)
        return 1e15;
    if (i == v.size())
    {
        return rem == 0 ? 0 : 1e15;
    }

    int &ret = memo[i][rem];
    if (~ret)
        return ret;

    ret = 1e15;

    for (int j = i; j < v.size(); j++)
    {
        int mid = (j + i) / 2;
        int sum = 0;
        for (int l = i; l <= j; l++)
        {
            sum += abs(v[mid] - v[l]);
        }
        ret = min(ret, sum + dp(j + 1, rem - 1));
    }

    return ret;
}

int kk = 1;
void dp_print(int i, int rem)
{
    if (rem < 0)
        return;
    if (i == v.size())
    {
        return;
    }

    int optimal = dp(i, rem);

    for (int j = i; j < v.size(); j++)
    {
        int mid = (j + i) / 2;
        int sum = 0;
        for (int l = i; l <= j; l++)
        {
            sum += abs(v[mid] - v[l]);
        }
        if (optimal == sum + dp(j + 1, rem - 1))
        {
            if (i != j)
                cout << "Depot " << kk++ << " at restaurant " << mid << " serves restaurants " << i << " to " << j << endl;
            else
                cout << "Depot " << kk++ << " at restaurant " << mid << " serves restaurant " << i << endl;
            dp_print(j + 1, rem - 1);
            return;
        }
    }
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
        kk = 1;
        memo.assign(n + 9, vector<int>(k + 9, -1));
        v.clear();
        v.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        cout << "Chain " << test << endl;
        dp_print(1, k);
        cout << "Total distance sum = " << dp(1, k) << endl;
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 1;
    while (cin >> n >> k, n && k)
    {
        sol(test++);
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
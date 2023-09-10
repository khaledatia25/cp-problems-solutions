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

#define OO (ll)1e18
#define oo (ll)1e9

using namespace std;
void fileInput(/*Hello World*/);

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const ll mod = 1e9 + 7;
const int sz = 2e5 + 9;
const ll N = 1e7 + 9;
double dp[10005];
vector<int> x;
vector<double> p;
double rec(int cur)
{
    if (cur > 10004)
        return 0.0;

    double &ret = dp[cur];
    if (ret == ret)
        return ret;
    ret = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] > 0)
        {
            ret += 1.0 * x[i] * p[i];
        }
        else
        {
            ret += 1.0 * -x[i] * p[i] + p[i] * rec(cur + 1);
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
        memset(dp, -1, sizeof dp);
        int n;
        cin >> n;
        x.resize(n);
        p.resize(n);
        bool a = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> p[i];
            if (x[i] > 0)
                a = 1;
        }
        cout << "Case " << test << ": ";
        if (a)
            cout << fixed << setprecision(2) << rec(0) << endl;
        else
            cout << "God! Save me" << endl;
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
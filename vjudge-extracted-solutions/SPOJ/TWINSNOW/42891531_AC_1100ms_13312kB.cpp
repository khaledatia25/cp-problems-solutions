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

const ll mod = 1e8;
const int sz = 2e5 + 9;

const ll N = 1e7 + 9;

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
        map<array<int, 6>, int> mp;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            array<int, 6> a;
            for (int &k : a)
                cin >> k;
            sort(all(a));
            mp[a]++;
        }
        if (mp.size() < n)
        {
            cout << "Twin snowflakes found." << endl;
        }
        else
        {
            cout << "No two snowflakes are alike." << endl;
        }
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 1;
    while (t--)
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
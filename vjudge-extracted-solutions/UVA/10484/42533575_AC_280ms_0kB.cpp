#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long long
#define int long long
#define OO 1e18
#define oo 1e9
using namespace std;
void fileInput();
const int N = 6000000 + 9;

int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};

const ll mod = 1e9 + 7;
const int sz = 2e5 + 9;

/*
10! = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1
    = 2 * 5 * 3 * 3 * 2 * 2 * 2 * 7 * 3 * 2 * 5 * 2 * 2 * 3 * 2
    = 2^8 * 3^4 * 5^2 * 7^1

d = 2^1;

    2^7   3^4   5^2  7^1
    we have 8*5*3*2 chices
*/

int32_t main()
{
    KHALED_WALEED_ATTIA
    function<void(int)> sol;
    fileInput();
    int n, m;
    sol = [&](int test) -> void
    {
        map<int, int> div1, div2;
        for (int i = 2; i <= n; i++)
        {
            int temp = i;
            for (int num = 2; num * num <= temp; num++)
            {
                while (temp % num == 0)
                {
                    div1[num]++;
                    temp /= num;
                }
            }
            if (temp != 1)
                div1[temp]++;
        }
        for (int num = 2; num * num <= m; num++)
        {
            while (m % num == 0)
            {
                div2[num]++;
                m /= num;
            }
        }
        if (m != 1)
            div2[m]++;

        for (auto i : div2)
        {
            if (i.second > div1[i.first])
            {
                cout << 0 << endl;
                return;
            }
            else
            {
                div1[i.first] -= i.second;
            }
        }
        int ans = 1;
        for (auto i : div1)
        {
            ans *= i.second + 1;
        }
        cout << ans << endl;
    };
    int t = 1;
    // cin >> t;
    int test = 1;
    while (cin >> n >> m, n || m)
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
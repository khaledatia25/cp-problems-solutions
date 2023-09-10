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
#define countbits(n) __builtin_popcount(n)

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
const int sz = 3e5 + 1;
const int K = 500 + 9;
const ll N = 1e7 + 9;

void init()
{
}
void elmtarshm(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    if (n & 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n / 2; i++)
    {
        int &a = v[i], &b = v[i + n / 2];
        if (a == -1 && b == -1)
        {
            a = b = 1;
        }
        else if (a == -1 || b == -1)
        {
            a = b = max(a, b);
        }
        else if (a != b)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto i : v)
        cout << i << space;
    cout << endl;
}

int32_t main()
{
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    init();
    int t = 1;
    cin >> t;
    int tc = 1;
    while (t--)
    {
        elmtarshm(tc++);
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
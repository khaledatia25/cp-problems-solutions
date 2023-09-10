/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <iostream>
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

const ll mod = 1e9 + 7ll;
const int sz = 2e5 + 9;
const ll N = 1e5 + 9;

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
        int low, high;
        while (cin >> low >> high, low && high)
        {

            int a = high / 5 + 1;
            int b = low / 5 + 1;
            cout << a - b + 1 << endl;
        }
    };

    // tests
    int t = 1;
    // cin >> t;

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
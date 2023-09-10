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
const ll N = 1e6 + 1;
vector<int> v;
int merge(int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> left(n1 + 2, OO), right(n2 + 2, OO);
    for (int i = 1; i <= n1; i++)
    {
        left[i] = v[l + i - 1];
    }
    for (int i = 1; i <= n2; i++)
    {
        right[i] = v[mid + i];
    }

    int i = 1;
    int j = 1;
    int ret = 0;
    for (int k = l; k <= r; k++)
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i++];
        }
        else
        {
            v[k] = right[j++];
            ret += (mid - i - l + 2);
        }
    }
    return ret;
}

int merge_sort(int l, int r)
{
    int ret = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        ret += merge_sort(l, mid);
        ret += merge_sort(mid + 1, r);

        ret += merge(l, mid, r);
    }
    return ret;
}

void init() {}
void elmtarshm(int tc)
{
    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    cout << merge_sort(1, n) << endl;
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
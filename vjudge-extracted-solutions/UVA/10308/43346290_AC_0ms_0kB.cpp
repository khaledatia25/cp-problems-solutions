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

#define OO (ll)3e18 + 5
#define oo (ll)1e9

using namespace std;
void fileInput(/*Hello World*/);

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const int sz = 2e5 + 9;
const ll N = 1e7 + 9;

ll mod = 1e9 + 7;

vector<vector<pair<int, int>>> graph;
pair<int, int> dfs(int node, int distance, int parent)
{
    pair<int, int> ret = {node, distance};

    for (auto next : graph[node])
    {
        if (next.first == parent)
            continue;

        auto temp = dfs(next.first, distance + next.second, node);

        if (temp.second > ret.second)
        {
            ret = temp;
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
    int n, m, sum = 0;
    // solution function
    function<void(int)> sol;
    const int lmt = 1ll * 1e9;
    string s;
    sol = [&](int test) -> void
    {
        int u, v, w;
        graph.assign(10001, vector<pair<int, int>>());
        while (s.size())
        {
            stringstream ss(s);
            ss >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
            getline(cin, s);
        }
        auto p1 = dfs(u, 0, u);

        auto p2 = dfs(p1.first, 0, p1.first);

        cout << p2.second << endl;
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 1;
    while (getline(cin, s))
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
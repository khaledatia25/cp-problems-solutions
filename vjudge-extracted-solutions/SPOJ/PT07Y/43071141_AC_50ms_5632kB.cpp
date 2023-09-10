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

/*
    Geometry Staff
*/

using namespace std;
void fileInput();

int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};

const ll mod = 1e9 + 7;

const int N = 1e5 + 3, M = 1e5 + 3;
int n, m;
int head[N], nxt[M], to[M], ne;

void init()
{
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}

void add_edge(int f, int t)
{
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void add_bi_edge(int u, int v)
{
    add_edge(u, v);
    add_edge(v, u);
}

bool vis[N];
int dfs(int u)
{
    if (vis[u])
        return 0;
    vis[u] = 1;
    int ret = 1;

    for (int e = head[u]; ~e; e = nxt[e])
    {
        ret += dfs(to[e]);
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
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            add_bi_edge(--u, --v);
        }

        if (n == m + 1 && dfs(0) == n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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
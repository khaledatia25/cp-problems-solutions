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

vector<vector<int>> adjMatrix;

void read_graph(vector<vector<int>> &adjMatrix)
{
    int n, m;
    cin >> n >> m;
    adjMatrix = vector<vector<int>>(n, vector<int>(m, oo));

    for (int i = 0; i < n; i++)

        adjMatrix[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        if (from == to)
            continue;

        adjMatrix[from][to] = min(weight, adjMatrix[from][to]);
    }
}

void floyed(vector<vector<int>> &adjMatrix, vector<vector<int>> &path)
{
    int n = adjMatrix.size();
    path.assign(n, vector<int>(n, -1));
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int relax = adjMatrix[i][k] + adjMatrix[k][j];
                if (adjMatrix[i][j] > relax)
                {
                    adjMatrix[i][j] = relax;
                    path[i][j] = k;
                }
            }
        }
    }
}

void build_path(int src, int dest, vector<vector<int>> &path)
{
    if (path[src][dest] == -1)
    {
        cout << src << space << dest << endl;
        return;
    }
    build_path(src, path[src][dest], path);
    build_path(path[src][dest], dest, path);
}

int dis(pair<int, int> i, pair<int, int> j)
{
    return (i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second);
}

void count_paths(vector<vector<int>> &graph)
{

    int n = graph.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                graph[i][j] += graph[i][k] * graph[k][j];
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        if (graph[k][k])
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][k] && graph[k][j])
                        graph[i][j] = -1;
                }
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
    int m, n, x, y;
    int cnt[31][31] = {};
    function<void(int)> sol;
    sol = [&](int test) -> void
    {
        memset(cnt, 0, sizeof(cnt));

        n = 0;
        while (m--)
        {
            cin >> x >> y;
            cnt[x][y]++;
            if (x > n)
                n = x;
            if (y > n)
                n = y;
        }
        n += 1;

        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = cnt[i][j];

        count_paths(graph);

        cout << "matrix for city " << test++ << endl;
        ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j)
                    cout << space;
                cout << graph[i][j];
            }
            cout << endl;
        }
    };

    // tests
    int t = 1;
    // cin >> t;

    // looooop
    int test = 0;
    while (cin >> m)
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
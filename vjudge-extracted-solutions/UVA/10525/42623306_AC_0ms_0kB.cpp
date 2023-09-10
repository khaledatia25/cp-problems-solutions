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

const ll N = 2e5 + 9;
vector<array<int, 2>> dist;
int Dijkstra(vector<vector<array<int, 3>>> &graph, int src, int dest = -1)
{
    int n = graph.size();
    array<int, 2> a = {oo, oo};
    dist.assign(n, a);
    dist[src][0] = dist[src][1] = 0;
    using pii = array<int, 3>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0, src});
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();

        if (dist[cur[2]][0] < cur[0] && dist[cur[2]][1] < cur[1])
            continue;

        for (auto edge : graph[cur[2]])
        {
            int dis = edge[0];
            int time = edge[1];
            int to = edge[2];
            if (dist[to][1] > cur[1] + time)
            {
                dist[to][0] = cur[0] + dis;
                dist[to][1] = cur[1] + time;
                pq.push({dist[to][0], dist[to][1], to});
            }
            else if (dist[to][1] == cur[1] + time)
            {
                if (dist[to][0] > cur[0] + dis)
                {
                    dist[to][0] = cur[0] + dis;
                    dist[to][1] = cur[1] + time;
                    pq.push({dist[to][0], dist[to][1], to});
                }
            }
        }
    }

    return dist[dest][0] == oo ? 0 : 1;
}
int32_t main()
{
    KHALED_WALEED_ATTIA
    function<void(int)> sol;
    fileInput();
    sol = [&](int test) -> void
    {
        int n, m;
        cin >> n >> m;
        vector<vector<array<int, 3>>> g(n + 1);
        for (int i = 0; i < m; i++)
        {
            int from, to, dis, time;
            cin >> from >> to >> time >> dis;
            // swap(time, dis);
            g[from].push_back({dis, time, to});
            g[to].push_back({dis, time, from});
        }
        int q;
        cin >> q;
        while (q--)
        {
            dist.clear();
            int s, d;
            cin >> s >> d;
            bool a = Dijkstra(g, s, d);
            // for (int i = 1; i <= n; i++)
            // {
            //     cout << dist[i][0] << space << dist[i][1] << endl;
            // }
            if (a)
            {
                cout << "Distance and time to reach destination is " << dist[d][0] << " & " << dist[d][1] << "." << endl;
            }
            else
            {
                cout << "No Path." << endl;
            }
        }
    };
    int t = 1;
    cin >> t;
    int test = 1;
    while (t--)
    {
        sol(test++);
        if (t)
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
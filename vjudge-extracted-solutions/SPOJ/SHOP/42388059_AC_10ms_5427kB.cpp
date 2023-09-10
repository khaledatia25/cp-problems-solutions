#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long  long
#define int long  long
#define OO 1e18
#define oo 1e9
using namespace std;
void fileInput();
const int N = 6000000+9;
int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};
const ll mod = 1e9+7;


vector<int>dist, path;

set<vector<int>>st;

int Dijkstra(vector<vector<pair<int, int>>>&graph,int src, int dest = -1){
    int n = graph.size();
    dist.assign(n, OO);
    path.assign(n, -1);
    dist[src] = 0;
    // v -> to , a, b
    using pii = pair<int, vector<int>>;
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({0, {src, -1}});

    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        if(cur.first != dist[cur.second[0]])
            continue;

        for(auto edge : graph[cur.second[0]]){
            int to = edge.second;
            int w = edge.first;
            if(st.find({cur.second[0], cur.second[1], to}) != st.end())
                    continue;
            if(dist[to] > cur.first + w){
                dist[to] = cur.first + w;
                path[to] = cur.second[0];
                pq.push({dist[to], {to, cur.second[0], cur.second[1]}});
            }
        }
    }

    return dest == -1 ? -1 : dist[dest];
}

void restore_path(int v){
    if(v == -1)
        return;
    restore_path(path[v]);
    cout<<v<<space;
}

int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    int n, m, k;
    sol = [&](int test) -> void {
        int x, y, a, b;
        char grid[30][30];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >>grid[i][j];
                if(grid[i][j] == 'S')
                    x=i, y=j;
                if(grid[i][j] == 'D')
                    a=i, b=j;
            
            }
        }
        auto valid = [&](int x, int y){
            if(x<n&&y<m&&x>=0&&y>=0&& grid[x][y]!='X'){
                return 1;
            }
            return 0;
        };
        vector<vector<int>>dist(30,vector<int>(30, oo));
        
        dist[x][y] = 0;
        using node = array<int, 2>;
        queue<node>q;
        q.push({x, y});
        // grid[x][y] = '9';
        grid[a][b] = '0';
        while(!q.empty()){
            node cur = q.front();
            q.pop();
            
            for(int k = 0; k < 4; k++){
                int nx = cur[0] + dx[k];
                int ny = cur[1] + dy[k];
                if(valid(nx, ny)){
                    if(dist[nx][ny] > dist[cur[0]][cur[1]] + grid[nx][ny] - '0'){
                        dist[nx][ny] = dist[cur[0]][cur[1]] + grid[nx][ny] - '0';
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout<<dist[a][b]<<endl;

    };
    int t = 1;
    // cin >>t;
    int test = 1;
    while(cin >>m >>n, n&&m){
        sol(test++);
    }

    return 0;
}


void fileInput(){
#ifndef ONLINE_JUDGE
   freopen("../input.txt", "r", stdin);
   freopen("../output.txt", "w", stdout);
#endif
}
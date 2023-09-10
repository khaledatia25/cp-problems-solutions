#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
typedef vector<vector<int>>GRAPH;
char mp[25][25];
int vis[25][25];
int dx[] = {0 , 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n,m, x, y;
char land;
vector<pair<ll, ll>>v(100009);
int cur;
void dfs(int x,int y){
    if(vis[x][y])
        return ;
    vis[x][y] = 1;
    cur++;    
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<n&&ny<m&&ny>=0 && mp[nx][ny] == land && !vis[nx][ny]){
         dfs(nx, ny);
        }
    }
    if(y == 0&& mp[x][m-1] == land&&!vis[x][m-1]){
         dfs(x, m-1);
    }
    if(y == m-1&& mp[x][0] == land&&!vis[x][0]){
        dfs(x,0);
    }
}
const ll mod = 1000000007; 
int main() {
    KHALED_WALEED_ATTIA
    while (cin >>n >>m)
    {   
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >>mp[i][j];
            }
        }
        cin >>x >>y;
        land = mp[x][y];
        int cnt = 0; 
        dfs(x, y);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mp[i][j] == land && !vis[i][j]){
                    cur = 0;
                    dfs(i, j);
                    cnt = max(cnt, cur);
                }
            }
        }
        cout<<cnt<<endl;
        memset(mp, 0, sizeof(mp));
        memset(vis, 0, sizeof(vis));
    }
    
    
    return 0;
}



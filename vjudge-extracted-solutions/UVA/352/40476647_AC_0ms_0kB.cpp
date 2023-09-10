#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};
const int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const int N = 10000;
bool vis[N];
vector<vector<int>>graph;
vector<int> aa;

void dfs(int node){
    if(vis[node])
        return;
    vis[node] = 1;
    // cout<<node<<space;
    for(int next : graph[node])
        dfs(next);
}
int main() {
    KHALED_WALEED_ATTIA
    int t = 1;; 
    // cin >>t;
    int n;
    while(cin >>n){
        graph = vector<vector<int>>(n*n+2);
        aa = vector<int>(n*n+2, -1);
        int  gg[n][n];
        char grid[n][n];
        int node = 1;
        vector<int>nodes;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >>grid[i][j], gg[i][j] = node++;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0')continue;
                nodes.push_back(gg[i][j]);
                for(int a = 0; a < 8; a++){
                    int x = i + dx[a];
                    int y = j + dy[a];
                    if(x>=0&&x<n&&y>=0&&y<n){
                        if(grid[x][y]=='1'){
                            graph[gg[i][j]].push_back(gg[x][y]);
                        }
                    }
                }
            }
        }        
        int ans = 0;
        for(int i  : nodes){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        cout<<"Image number "<<t++<<" contains "<<ans<<" war eagles."<<endl;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}



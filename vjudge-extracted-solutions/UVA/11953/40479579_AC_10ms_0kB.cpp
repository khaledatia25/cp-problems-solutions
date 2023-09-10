#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
const int N = 10000;
vector<vector<int>>graph;
vector<int> aa;
char grid[109][109];
int vis[109][109];
int dx[] = {0, 0, 1,-1};
int dy[] = {1, -1, 0, 0};
int n,m;
bool valid(int i, int j) {return (i>=0&&i<n&&j>=0&&j<n);}
vector<string>ans;
bool dfs(int i, int j){
    if(vis[i][j])
        return 0;
    vis[i][j] = 1;   
    bool ret = 0; 
    if(grid[i][j] == 'x')ret=1;
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        // cout<<x<<space<<y<<space<<valid(x, y)<<endl;
        if(valid(x, y) && (grid[x][y] != '.')){
            // cout<<1<<endl;
            ret = dfs(x,y) || ret;
        }
    }
    return ret;
}
int main() {
    KHALED_WALEED_ATTIA
    int t = 1;
    cin >>t;
    int tt=1;
    while(t--){
        cin >>n;
        int node = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >>grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 'x'){
                    ans += dfs(i,j);
                }
            }
        }
        cout<<"Case "<<tt++<<": "<<ans<<endl;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}



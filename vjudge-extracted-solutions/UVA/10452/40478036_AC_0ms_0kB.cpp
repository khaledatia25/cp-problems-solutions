#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
const int N = 10000;
bool vis[N];
vector<vector<int>>graph;
vector<int> aa;
char grid[10][10];
int dx[] = {-1, 0, 0};
int dy[] = {0, 1, -1};
string dr[] = {"forth", "right", "left"};
string path = "IEHOVA#";
int n,m;
bool valid(int i, int j) {return (i>=0&&i<n&&j>=0&&j<m);}
vector<string>ans;
void dfs(int i, int j, int idx){
    if(idx >= path.size())
        return;
    for(int k = 0; k < 3; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(valid(x, y)&&grid[x][y] == path[idx]){
            ans.push_back(dr[k]);
            dfs(x,y,idx+1);
        }
    }
}
int main() {
    KHALED_WALEED_ATTIA
    int t = 1;
    cin >>t;
    while(t--){
        cin >>n >>m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >>grid[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == '@'){
                    dfs(i, j,0);
                    break;
                }
        cout<<ans[0];
        for(int i = 1; i < ans.size(); i++)cout<<space<<ans[i];
        cout<<endl;
        ans.clear();
        
    }
    return 0;
}



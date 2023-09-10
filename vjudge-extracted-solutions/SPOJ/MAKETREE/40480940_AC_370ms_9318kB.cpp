#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
const int N = 10000;
typedef vector<vector<int>> GRAPH;
GRAPH graph(100009);
int n, m;
vector<int>ans;
int vis[100009];
void dfs(int node){
    if(vis[node])
        return;
    vis[node] = 1;
    for(int next : graph[node]){ 
        dfs(next);
    }
    ans.push_back(node);
    
}

int main() {
    KHALED_WALEED_ATTIA
    cin >>n >>m;
    for(int i = 1; i <= m; i++){
        int l, s;
        cin >>l;
        for(int j = 0; j < l; j++){
            cin >>s;
            graph[i].push_back(s);
        }
    }
    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    vector<int>fin(n+1,0);
    int p = 0;
    for(int i = n-1; i >= 0; i--){
        int s = ans[i];
        fin[s] = p;
        p = s; 
    }
    for(int i = 1; i <= n; i++)
        cout<<fin[i]<<endl;
    return 0;
}



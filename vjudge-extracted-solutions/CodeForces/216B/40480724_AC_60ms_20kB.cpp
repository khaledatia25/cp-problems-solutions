#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
const int N = 10000;
typedef vector<vector<int>> GRAPH;
GRAPH graph(103);
vector<int>vis(109);
int n, m;

bool dfs(int node,int parent, int &cnt){
    if(vis[node] == 1){
        return 1;
    }
    vis[node] = 1;
    for(int next : graph[node])if(next != parent){
        cnt++;    
        if(dfs(next,node, cnt))
            return 1;
    }
    return 0;
}

int main() {
    KHALED_WALEED_ATTIA
    cin >>n >>m;
    for(int i = 0; i < m; i++){
        int p1, p2;
        cin >>p1 >>p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }
    int remove = 0;
    for(int node = 1; node <= n; node++)if(!vis[node]){
        int cnt = 0;
        bool sol = dfs(node,-1, cnt);
        // cout<<cnt<<endl;
        // cout<<sol<<endl;
        if(sol)
            remove += (cnt&1); 
    }

    if((n-remove)&1)
        remove++;
    cout<<remove<<endl;    
    return 0;
}



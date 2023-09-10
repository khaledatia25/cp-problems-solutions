#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
typedef vector<vector<int>>GRAPH;
vector<int>vis;
vector<int>ans;
GRAPH graph;
void top_sort(int node){
    if(vis[node])
        return;
    vis[node] = 1;
    for(int next_node : graph[node]){
        top_sort(next_node);
    }    
    ans.push_back(node);
}

int main() {
    KHALED_WALEED_ATTIA
    int n,m;
    while(cin >>n >>m, n){
        graph = GRAPH(n+1);
        vis = vector<int>(n+1,0);
        int from, to;
        for(int i = 0; i < m; i++){
            cin >>from >>to;
            graph[from].push_back(to);
        }
        for(int i = 1; i <= n; i++){
            top_sort(i);
        }
        reverse(ans.begin(), ans.end());
        for(int i : ans)
            cout<<i<<space;
        cout<<endl;
        ans.clear();    
    }
    return 0;
}



#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1},
        dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const ll mod = 1000000007;
vector<int>ans;
void rec(int i,vector<int>nodes,vector<bool>&color,vector<vector<int>>&graph){
    if(i == graph.size()){
        if(nodes.size() > ans.size()){
            ans = nodes;
        }
        return;
    }
    bool valid = 1;
    for(int node : graph[i]){
        if(color[node])
            valid=0;
    }
    if(valid){
        nodes.push_back(i);
        color[i] = 1;
        rec(i+1, nodes, color, graph);
        nodes.pop_back();
        color[i] = 0;
    }
    rec(i+1, nodes, color, graph);
}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int m; cin>>m;
    while(m--){
        int n, k;
        cin>>n>>k;
        vector<vector<int>>graph(n+1);
        for(int i = 0; i<k;i++){
            int from, to;
            cin >>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        vector<bool>color(n+1,0);
        ans.clear();
        rec(1, {},color, graph);
        cout<<ans.size()<<endl;
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i];
            if(i!=ans.size()-1)cout<<space;
        }
        cout<<endl;

    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

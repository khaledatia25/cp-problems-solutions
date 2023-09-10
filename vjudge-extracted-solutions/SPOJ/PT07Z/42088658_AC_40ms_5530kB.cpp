#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
#define int long long
using namespace std;
void fileInput();
const int N = 6000000+9;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1},
        dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

const ll mod = 1e9+7;
vector<vector<int>>g;
vector<int>len;
vector<bool>vis;
int mx,nd;
void dfs(int node,int d){
    if(vis[node])
        return;
    vis[node] = 1;
    mx = max(mx, d);
    if(mx == d)
        nd = node;
    for(int next : g[node]){
        if(!vis[next]){
            dfs(next, d+1);
        }
    }
}
int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    sol = [&](int test) -> void {
        int n;
        cin >>n;
        g.resize(n+1);
        vis.resize(n+1);
        for(int i = 1; i < n; i++){
            int from, to;
            cin >>from  >>to;
            g[from].push_back(to);
            g[to].push_back(from);
        }
        dfs(1, 0);
        std::fill(vis.begin(), vis.end(), 0);
        dfs(nd, 0);
        cout<<mx<<endl;
    };
    int t = 1;
//    cin >>t;
    int test = 1;
    while(t--){
        sol(test++);
    }

    return 0;
}
/*

 */


void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
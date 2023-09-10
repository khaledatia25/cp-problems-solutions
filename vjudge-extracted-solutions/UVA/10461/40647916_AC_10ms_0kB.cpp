#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
typedef vector<vector<int>>GRAPH;
GRAPH g, m;

int main() {
    KHALED_WALEED_ATTIA
    int v, e;
    int ttt=1;
    while(cin >>v >>e){
        if(!v&&!e)break;
        g = GRAPH(v+1);
        m = GRAPH(v+1);
        vector<int>a(v+1);
        int sum = 0;
        for(int i = 1; i <= v; i++)
            cin >>a[i], sum += a[i];  
        for(int i = 0; i < e; i++){
            int from, to;
            cin >>from >>to;
            g[from].push_back(to);
            m[to].push_back(from);
        }
        vector<int>vis;
        int q;
        cin >>q;
        cout<<"Case #"<<ttt++<<":\n";
        while(q--){
            int x;
            cin >>x;
            int mn = -a[x], mx = sum;
            queue<int>qu;
            vis = vector<int>(v+1, 0);
            qu.push(x);
            while(!qu.empty()){
                int cur = qu.front();
                qu.pop();
                mn += a[cur];
                for(int next : g[cur])if(!vis[next]){
                    qu.push(next);
                    vis[next] = 1;
                }
            }
            vis = vector<int>(v+1, 0);
            qu.push(x);
            while(!qu.empty()){
                int cur = qu.front();
                qu.pop();
                mx -= a[cur];
                for(int next : m[cur])if(!vis[next]){
                    qu.push(next);
                    vis[next] = 1;
                }
            }
            cout<<abs(mx-mn)<<endl;
        }
        cout<<endl;
    
    }
    return 0;
}



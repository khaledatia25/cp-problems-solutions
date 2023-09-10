#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long  long
#define int long  long
#define OO 1e18
#define oo 1e9
using namespace std;
void fileInput();
const int N = 6000000+9;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1},
    dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1e9+7;


class Edge {
public:
    int from, to, w;
    Edge(int f, int t, int w) : from(f), to(t), w(w){}

    bool operator < (const Edge &e) const {
        return w > e.w; // > to reverse order
    }
};

int Dijkstra(vector<vector<Edge>>&graph, int src, int dest = -1){
    int n = graph.size();
    vector<int> dist(n, oo), prev(n, -1);
    bool vis[n+1] = {0};
    priority_queue<Edge> pq;
    pq.push(Edge(-1, src, 0));
    dist[src] = 0;
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();

        if(e.w > dist[e.to])
            continue;       // some other state reached better

    
        prev[e.to] = e.from;

        for(auto j : graph[e.to]){
            Edge next = j;
            if(dist[next.to] > dist[next.from] + next.w){
                next.w = dist[next.to] = dist[next.from] + next.w;
                pq.push(next);
            }
        }
    }
    return dest == -1 ? -1 : dist[dest];
}


int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    int n, m, s, d;
    sol = [&](int test) -> void {
        cin >>n >>m >>s >>d;
        vector<vector<Edge>>g(n+1);
        for(int i = 0; i < m; i++){
            int from , to , w;
            cin >>from >>to >>w;
            g[from].push_back(Edge(from, to , w));
            g[to].push_back(Edge(to, from , w));
        }
        int ans = Dijkstra(g, s, d);
        cout<<"Case #"<<test<<": ";
        if(ans != oo)
            cout<<ans<<endl;
        else
            cout<<"unreachable"<<endl;
    };
    int t = 1;
    cin >>t;
    int test = 1;
    while(t--){
        sol(test++);
    }

    return 0;
}



void fileInput(){
#ifndef ONLINE_JUDGE
   freopen("../input.txt", "r", stdin);
   freopen("../output.txt", "w", stdout);
#endif
}
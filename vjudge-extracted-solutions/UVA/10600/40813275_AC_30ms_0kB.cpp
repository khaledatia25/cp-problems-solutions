#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;
typedef vector<vector<ll>>GRAPH;

const ll mod = 1000000007;

// MST Algorithm
struct edge {
    int from, to, w;

    edge(int from, int to , int w):from(from), to(to), w(w){};

    bool operator < (const edge & e) const {
        return w > e.w;
        // STL priority queue need it > , or modify data -ve use parameter less
    }
};
// Disjoint set data structure
struct UnionFind {
    vector<int> rank, parent;
    int forests;

    UnionFind(int n) {
        rank = vector<int>(n + 1);
        parent = vector<int>(n + 1);
        forests = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find_set(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find_set(parent[x]);
    }

    void link(int x, int y) {
        if (rank[x] > rank[y])swap(x, y);
        parent[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }

    bool union_set(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            link(x, y);
            forests--;
        }
        return x != y;
    }
};

pair<int, vector<edge>> MST_Kruskal(vector<edge>edgeList, int n){
    UnionFind uf(n);

    vector<edge>edges;
    priority_queue<edge> q;

    int mstCost = 0;
    for(edge e : edgeList){
        q.push(e);
    }

    while(!q.empty()){
        edge e = q.top();
        q.pop();

        if(uf.union_set(e.from, e.to)){
            mstCost += e.w;
            edges.push_back(e);
        }
    }
    if(edges.size() != n-1)
        return {INT_MAX, vector<edge>()};
    return make_pair(mstCost, edges);

}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    cin >>t;
    while(t--){
        int n, ee;
        cin >>n >>ee;
        vector<edge>edges;
        for(int i = 0; i < ee; i++){
            int from, to, w;
            cin >>from >>to >>w;
            edges.push_back(edge(from, to, w));
        }
        pair<int, vector<edge>>ans = MST_Kruskal(edges,n);
        int mi = INT_MAX;
        for(edge e : ans.second){
            vector<edge>new_edges;
            for(int i = 0; i < ee; i++){
                if(edges[i].from == e.from && edges[i].to == e.to && edges[i].w == e.w)
                    continue;
                new_edges.push_back(edges[i]);
            }
            auto ans2 = MST_Kruskal(new_edges, n);
            mi = min(mi, ans2.first);
        }
        cout<<ans.first<<space<<mi<<endl;
    }
    return 0;
}




void fileInput(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


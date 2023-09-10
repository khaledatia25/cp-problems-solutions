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

vector<edge> MST_Kruskal(vector<edge>edgeList,vector<pair<int,int>>done, int n){
    UnionFind uf(n);
    for(auto  i : done){
        uf.union_set(i.first, i.second);
    }
    vector<edge>edges;
    priority_queue<edge> q;

    for(edge e : edgeList){
        q.push(e);
    }

    while(!q.empty()){
        edge e = q.top();
        q.pop();

        if(uf.union_set(e.from, e.to)){
            edges.push_back(e);
        }
    }
    return edges;

}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        vector<pair<int, int>>v;
        for(int i = 0; i<n; i++){
            int x, y;
            cin >>x >>y;
            v.emplace_back(x, y);
        }
        vector<edge>edges;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int xx= v[i].first - v[j].first;
                int yy= v[i].second - v[j].second;
                edges.push_back(edge(i+1, j+1, xx*xx+yy*yy));
            }
        }
        int x;
        cin >>x;
        vector<pair<int, int>>done;
        for(int i = 0; i < x; i++){
            int from, to;
            cin >>from >>to;
            done.emplace_back(from, to);
        }
        vector<edge>ans;
        ans = MST_Kruskal(edges, done, n);
        if(ans.size() == 0){
            cout<<"No new highways need"<<endl;
        }
        for(auto i : ans){
                cout<<i.from<<space<<i.to<<endl;
        }
        if(t)
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


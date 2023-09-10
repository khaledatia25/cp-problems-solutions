#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;
typedef vector<vector<ll>>GRAPH;

const ll mod = 1000000007;


struct edge {
    int from, to;
    ll w;

    edge(int from, int to , ll w):from(from), to(to), w(w){};

    bool operator < (const edge & e) const {
        return w > e.w;
        // STL priority queue need it > , or modify data -ve use parameter less
    }
};
// Disjoint set data structure
// Disjoint set data structure
struct DSU {
    vector<int> rank, parent;
    int forests;

    DSU(int n) {
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

    int union_set(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            link(x, y);
            forests--;
        }
        return x!=y;
    }
};

vector<edge> MST_K(vector<edge>edges, int n){
    DSU dsu(n);
    priority_queue<edge>q;
    for(edge e: edges){
        q.push(e);
    }
    vector<edge>ret;
    while(!q.empty()){
        edge e = q.top();
        q.pop();
        if(dsu.union_set(e.from, e.to)){
            ret.push_back(e);
        }
    }
    if(ret.size() != n-1)
        return {};
    return ret;
}


int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    cin >>t;
    while(t--){
        int n, m;
        cin >>n >>m;
        vector<pair<ll, ll>>cor(m);
        for(int i = 0; i < m; i++){
            cin >>cor[i].first >>cor[i].second;
        }
        vector<edge>edges;
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m; j++){
                int xx = cor[i].first - cor[j].first;
                int yy = cor[i].second - cor[j].second;
                edges.push_back(edge(i+1, j+1, xx*xx+yy*yy));
            }
        }
        vector<edge>ans = MST_K(edges, m);
        cout<<fixed<<setprecision(2)<<sqrt((double)ans[m-n-1].w)<<endl;


    }
    return 0;
}




void fileInput(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


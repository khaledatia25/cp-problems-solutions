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
    int from, to, w;

    edge(int from, int to , int w):from(from), to(to), w(w){};

    bool operator < (const edge & e) const {
        return w > e.w;
        // STL priority queue need it > , or modify data -ve use parameter less
    }
};
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
        if (rank[x] <= rank[y]) rank[y]+=rank[x];
    }

    int union_set(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            link(x, y);
            forests--;
        }
        return max(rank[x],rank[y]);
    }
};


int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    cin >>t;
    string name1, name2;
    while(t--){
        int n;
        cin >>n;
        vector<pair<string, string>>edges(n);
        int next = 1;
        map<string, int>mp;
        for(int i = 0; i<n; i++){
            cin >>edges[i].first >>edges[i].second;
            if(!mp[edges[i].first])
                mp[edges[i].first] = next++;
            if(!mp[edges[i].second])
                mp[edges[i].second] = next++;
        }
        DSU dsu(next-1);
        for(int i = 0; i < n; i++){
            int x = mp[edges[i].first];
            int y = mp[edges[i].second];

            cout<< dsu.union_set(x, y) <<endl;
        }

    }
    return 0;
}




void fileInput(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


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

struct node{
    int value = 0;
    node* right = nullptr;
    node* left = nullptr;
    node(int val):value(val){
        right = nullptr;
        right = nullptr;
    }
};
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    string s;
    int mx = 0;
    vector<pair<string, string>>v;
    while(getline(cin, s)){
        stringstream ss(s);
        string c;
        bool ddd = 0;
        int r = -1;
        while(ss >>c){
            if(c == "()"){
                ddd=1;
                break;
            }
            string num,  path;
            int i;
            for(i = 1; i < c.size(); i++){
                if(c[i] != ',')
                    num.push_back(c[i]);
                else break;
            }
            i++;
            for(i;i<c.size();i++){
                if(c[i] != ')')
                    path.push_back(c[i]);
            }
            if(path == "")
                r = stoi(num);
            v.emplace_back(path, num);
//            cout<<path<<space<<num<<endl;
        }
        if(ddd){
            bool complete = 1;
            node root(-1);
            node  *cur = &root;
            for(auto i : v){
                cur = &root;
                for(int j = 0; j <  i.first.size(); j++){
//                    cout<<i.first[j];
                    if(i.first[j] == 'L'){
                        if(cur->left != nullptr){
                            cur = cur->left;
                        }else{
//                            cout<<1;
                            cur->left = new node(-1);
                            cur = cur->left;
                        }
                    }else{
                        if(cur->right != nullptr){
                            cur = cur->right;
                        }else{
//                            cout<<1;
                            cur->right = new node(-1);
                            cur = cur->right;
                        }
                    }
//                    cout<<space;
                }
//                cout<<endl;
                    if(cur->value == -1)
                        cur->value = stoi(i.second);
                    else
                        complete = 0;
//                    cout<<cur->value<<endl;
            }
            queue<node*>q;
            q.push(&root);
            vector<int>ans;
            while(!q.empty()){
                node* cur = q.front();

                if(cur->value == -1)
                    complete = 0;
                ans.push_back(cur->value);
                q.pop();
                if(cur->left != nullptr){
                    q.push(cur->left);
                }
                if(cur->right!= nullptr)
                    q.push(cur->right);
            }
            if(complete){
                cout<<ans[0];
                for(int i = 1;i < ans.size(); i++)cout<<space<<ans[i];
                cout<<endl;
            }else{
                cout<<"not complete"<<endl;
            }
            v.clear();

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


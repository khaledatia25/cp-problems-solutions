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
class Node {
public:
    int x, y, c;
    Node(){
        x=y=c=-1;
    }
    Node(int x, int y, int c) : x(x), y(y), c(c){

    }
    Node operator = (Node const &o){
        this->x = o.x;
        this->y = o.y;
        this->c = o.c;
        return *this;
    }
};
int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();

    sol = [&](int test) -> void {
        int n, m;
        cin >>n >>m;
        int arr[n+1][m];
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >>s;
            for (int j = 0; j < m; ++j) {
                arr[i][j+1] = s[j]-'0';
            }
        }
        int t=1;
        cin >>t;
        while(t--){
            deque<Node>dq;
            int x, y;
            cin >>x >>y;
            vector<vector<int>>dist(n+1, vector<int>(m+1, INT_MAX));
            Node src(x, y, 0);
            cin >>x >>y;
            dq.push_front(src);
            dist[src.x][src.y] = 0;
            bool done = 0;
            while(!dq.empty()){
                Node cur = dq.front();
//                cout<<cur.x<<space<<cur.y<<endl;
                dq.pop_front();
                if(x == cur.x && y == cur.y){
                    cout<<cur.c<<endl;
                    done = 1;
                    break;
                }
                for(int i = 0; i < 8; i++){
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if(nx>0&&nx<=n&&ny>0&&ny<=m){
                        if (i == arr[cur.x][cur.y]) {
                                if(dist[nx][ny] > cur.c){
                                    dist[nx][ny] = cur.c;
                                    dq.push_front(Node(nx, ny, cur.c));
                                }
                        } else {
                            if(dist[nx][ny] > cur.c + 1){
                                dist[nx][ny] = cur.c + 1;
                                dq.push_back(Node(nx, ny,cur.c+1));
                            }
                        }
                    }
                }
            }
            if(!done)
                cout<<dist[x][y]<<endl;
        }

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
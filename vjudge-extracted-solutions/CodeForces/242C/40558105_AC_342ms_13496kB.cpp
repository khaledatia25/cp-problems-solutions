#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
typedef vector<vector<int>>GRAPH;
int dix[] = {1, -1 , 0, 0,1,1,-1,-1};
int diy[] = {0, 0, 1, -1,-1,1,1,-1 };
map<pair<int, int>, bool>points;
map<pair<int, int>, bool>vis;
int BFS(pair<int, int>start, pair<int, int>target){
    queue<pair<pair<int, int>, int>>qu;
    qu.push({start, 0});
    int moves = 0;
    vis[start] = 1;
    while(!qu.empty()){
        pair<int, int> cur = qu.front().first;
        moves = qu.front().second;
        if(target == cur)
            return moves;
        qu.pop(); 
        for(int d = 0; d < 8; d++){
            pair<int, int>next = {cur.first+dix[d], cur.second+diy[d]};
            if(points[next] && !vis[next]){
                vis[next] = 1;
                qu.push({next, moves+1});  
            }
        }

    }
    return -1;
}
int main() {
    KHALED_WALEED_ATTIA
    int x0, y0, xn, yn;
    cin >>x0 >>y0 >>xn >>yn;
    int n;
    cin >>n;
    for(int i = 0; i < n; i++){
        int r,x,y;
        cin >>r >>x >> y;
        for(x;x<=y;x++){
            points[{r, x}] = 1;
        }
    }
    cout<<BFS({x0,y0},{xn,yn})<<endl;
    return 0;
}



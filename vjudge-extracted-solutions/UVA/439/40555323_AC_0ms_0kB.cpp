#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
typedef vector<vector<int>>GRAPH;
int vis[9][9];
vector<pair<int, int>> generate_move(int i, int j){
    vector<pair<int, int>>ans;
    if(i+2<9){
        if(j+1<9)
            ans.emplace_back(i+2,j+1);
        if(j-1>0)
            ans.emplace_back(i+2, j-1);    
    }
    if(i-2>0){
        if(j+1<9)
            ans.emplace_back(i-2,j+1);
        if(j-1>0)
            ans.emplace_back(i-2, j-1);    
    }
    if(j+2<9){
        if(i+1<9)
            ans.emplace_back(i+1,j+2);
        if(i-1>0)
            ans.emplace_back(i-1, j+2);    
    }
    if(j-2>0){
        if(i+1<9)
            ans.emplace_back(i+1,j-2);
        if(i-1>0)
            ans.emplace_back(i-1, j-2);    
    }
    return ans;

}
int BFS(pair<int, int>start, pair<int, int>target){
    queue<pair<pair<int, int>, int>>qu;
    qu.push({start, 0});
    int moves = 0;
    vis[start. first][start. second] = 1;
    while(!qu.empty()){
        pair<int, int> cur = qu.front().first;
        moves = qu.front().second;
        if(target == cur)
            return moves;
        qu.pop();
        auto next = generate_move(cur.first, cur.second);
        for(pair<int, int> next_cell : next){
            if(!vis[next_cell.first][next_cell.second]){
                vis[next_cell.first][next_cell.second] = 1;
                qu.push({next_cell, moves+1});  
            }
        }

    }
    return -1;
}
int main() {
    KHALED_WALEED_ATTIA
    int n=1;
    // cin >>n;
    string s, e;
    while(cin >>s >>e){
        pair<int, int>start = {s[0]-'a'+1, s[1]-'0'}, end = {e[0]-'a'+1, e[1]-'0'};
        cout<<"To get from "<<s<<" to "<<e<<" takes "<<BFS(start, end)<<" knight moves."<<endl;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}



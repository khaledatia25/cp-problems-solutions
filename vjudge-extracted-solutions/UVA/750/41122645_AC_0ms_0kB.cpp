#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1},
        dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const ll mod = 1000000007;

int attack[10][10];
void set_attack(int x, int y, int value){
    for(int i = 1; i < 9; i++)
        if(value)
            attack[x][i]++, attack[i][y]++;
        else
            attack[x][i]--, attack[i][y]--;
    for(int d = 4; d < 8; d++){
        int new_x = x, new_y = y;
        while(1){
             new_x += dx[d];
             new_y += dy[d];
            if(new_x<1||new_x>8||new_y<1||new_y>8)
                break;
            if(value)
                attack[new_x][new_y] += 1;
            else
                attack[new_x][new_y] -= 1;
        }
    }
}
vector<string>ans;
int x, y;
void rec(int c, string s){
    if(c > 8){
        if(s.size() == 8)
            ans.push_back(s);
        return;
    }
    if(c == y){
        s+= to_string(x);
        rec(c+1, s);
        return;
    }
    for(int r = 1; r < 9; r++){
        if(!attack[r][c]){
            set_attack(r, c, 1);
            s.push_back(r+'0');
            rec(c+1, s);
            set_attack(r, c, 0);
            s.pop_back();
        }
    }
}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t; cin>>t;
    while(t--){
        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        cin >>x>>y;
        memset(attack, 0, sizeof attack);
        set_attack(x,y, 1);
        ans.clear();
        rec(1,"");
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            if(i<9)cout<<space;
            cout<<i+1<<"      "<<ans[i][0];
            for(int j = 1; j < ans[i].size(); j++){
                cout<<space<<ans[i][j];
            }
            cout<<endl;
        }
        if(t)cout<<endl;
    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

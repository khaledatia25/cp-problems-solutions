#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define ll long  long
using namespace std;
typedef vector<vector<int>>GRAPH;
vector<int>vis;
vector<int>ans;
bool is_win(string s){
    bool row =  (s[0]!='.' && s[0] == s[1] && s[1] == s[2])||
                (s[3]!='.'&&s[3]==s[4]&&s[4]==s[5])||
                (s[6]!='.'&&s[6]==s[7]&&s[7]==s[8]);
    bool col =  (s[0]!='.' && s[0] == s[3] && s[3] == s[6])||
                (s[1]!='.'&&s[1]==s[4]&&s[4]==s[7])||
                (s[2]!='.'&&s[2]==s[5]&&s[5]==s[8]);
    bool dig =  (s[0]!='.' && s[0] == s[4] && s[4] == s[8])||
                (s[2]!='.'&&s[2]==s[4]&&s[4]==s[6]);
    return row||col||dig;            
}
int main() {
    KHALED_WALEED_ATTIA
    int n;
    // cin >>n;
    while(1){
        string s = "";
        cin >>s;
        if(s=="end")break;
        queue<pair<string, bool>>q;
        string start = ".........";
        string ans = "invalid";
        q.push(make_pair(start, 0));
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(cur.first == s){
                bool t=1;
                for(char i : cur.first)if(i == '.')t=0;
                if(is_win(cur.first) || t)
                    ans = "valid";
                break;    
            }
            if(is_win(cur.first))
                continue;
            for(int i = 0; i < 9; i++){
                if(cur.first[i] != '.')continue;
                cur.first[i] = cur.second ? 'O' : 'X';
                if(cur.first[i] == s[i]){
                    q.push({cur.first, !cur.second});
                }
                cur.first[i] = '.';
            }    
        }
        cout<<ans<<endl;
    }
    return 0;
}



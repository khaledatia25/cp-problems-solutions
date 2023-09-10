//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

ll t=1, n,x, max_weight = 13,m;
vector<vector<ll>>v;
ll sum = 0;
int rotated[10000009] = {0};
//return number of digits
int numberLen(ll n){
    string s = to_string(n);
    return s.size();
}
//return a number after doing operation two
ll operationTwo(ll n){
    string s = to_string(n);
    s = s[s.size()-1]+s.substr(0,s.size()-1);
    return stoi(s);
}
vector<int>ans;
void p(ll x,ll a,int cnt=0){
    if(x == m) {
        ans.push_back(cnt);
        return;
    }
    if(numberLen(x) > numberLen(m))
        return ;

    ll xx = operationTwo(x);
    if(rotated[xx] == 0 && x>=10&&x%10!=0){
        rotated[xx]=1;
        rotated[x] = 1;
        p(xx,a,cnt+1);
        rotated[xx]=0;
    }
    p(a*x,a,cnt+1);
}

int main() {
    init();
//    cin >>t;
    while(t--){
        string s;
        cin >>s;
        int h=1;
        int cnt =0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0')cnt++;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'&&h&&cnt){
                h=0;
                continue;
            }
            if(cnt == 0&&h){
                h=0;
                continue;
            }
            cout<<s[i];
        }

    }

    return 0;
}



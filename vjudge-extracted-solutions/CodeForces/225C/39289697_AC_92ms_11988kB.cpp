/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define endl "\n"
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;

ll n,m,k,x,y;
int t=1;

int dp[1005][1005][3];
vector<int>dots;
string s;

ll rec(int i, int w, int type){
    if(i == m){
        if(w<x || w>y)
            return 1e9;
        return 0;    
    }   

    int &ret = dp[i][w][type];
    if(~ret)return ret;

    int dot = 1e6+1;

    if(i == 0 || (type == 0 && w+1 <= y) || (type == 1 && w>= x))
            dot = n - dots[i] + rec(i+1, (type==0) ? w+1:1, 0);

    int hashes = 1e6+1;

    if(i == 0 || (type == 1 && w+1 <= y) || (type == 0 && w>=x))
            hashes = dots[i] + rec(i+1, (type == 1)?w+1:1, 1);

    ret = min(dot, hashes);

    return ret;        

}

int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    bool f = 0;
    while(t--){
        cin >>n >>m >>x >>y;
        dots = vector<int>(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >>c;
                if(c=='.')dots[j]++;
            }
        }
        memset(dp, -1, sizeof(dp));
        cout<<rec(0,0, 2)<<endl;
         
    }
    return 0;
}
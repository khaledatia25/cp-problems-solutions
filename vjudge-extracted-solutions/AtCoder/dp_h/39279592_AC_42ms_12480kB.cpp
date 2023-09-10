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
const int N = 200005;

ll n,m;
int t=1;
char grid[1005][1005];
ll dp[1005][1005];

ll rec(int i, int j){
    if(i == n || j == m)
        return 0;
    if(grid[i][j] == '#')
        return 0;
    if(i == n-1 && j == m-1)
        return 1;
    ll &ret = dp[i][j];
    if(~ret)return dp[i][j];
    ret = rec(i+1, j)%MOD  + rec(i, j+1)%MOD;
    ret %= MOD;
    return ret;       
}

int main() {
    FIO;  
    // cin >>t;
    // int cnt=1;
    while(t--){
        cin >>n >>m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >>grid[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout<<rec(0,0)<<endl;
    }
    return 0;
}
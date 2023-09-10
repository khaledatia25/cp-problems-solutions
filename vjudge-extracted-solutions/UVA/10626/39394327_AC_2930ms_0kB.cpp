/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define setting(x, i) memset(x, i, sizeof(x))
#define endl "\n"
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;
ll inf = 1e9+1;
ll n,m,k,x,y;
int t=1;



vector<int>v;
vector<vector<ll>>colors;
ll dp[850][350][300];

ll sol(int n1, int n5,int n10, int i){
    if(i == n)
        return 0;
    ll& ret = dp[n1][n5][n10];
    if(~ret)return ret;
    ret=1e9+1;
    if(n10>0)ret = min(ret, sol(n1+2, n5, n10-1, i+1)+1);
    if(n5>1)ret = min(ret, sol(n1+2, n5-2, n10, i+1)+2);
    if(n1>7)ret = min(ret, sol(n1-8, n5, n10, i+1)+8);
    if(n5 and n1>2)ret=min(ret, sol(n1-3, n5-1, n10, i+1)+4);
    if(n10 and n1>2)ret=min(ret, sol(n1-3, n5+1, n10-1, i+1)+4);
    return ret;
}

int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    while(t--){
        int c, n1, n5, n10;
        cin >>n >>n1 >>n5 >>n10;
        setting(dp, -1);
        cout<<sol(n1,n5,n10, 0)<<endl;;

    }
    return 0;
}
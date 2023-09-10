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
int a[100005], b[100005], c[100005];
ll dp[4][100005];

ll rec(int i, int prev){
    if(i == n)
        return 0;

    ll &ret = dp[prev][i];
    if(~ret)return ret;
    if(prev == 0)
        ret = max({a[i] + rec(i+1, 1), b[i] + rec(i+1, 2), c[i] + rec(i+1, 3)});
    else if(prev == 1)
        ret = max(b[i] + rec(i+1, 2), c[i] + rec(i+1, 3));    
    else if(prev == 2)
        ret = max(a[i] + rec(i+1, 1), c[i] + rec(i+1, 3));    
    else if(prev == 3)
        ret = max(a[i] + rec(i+1, 1), b[i] + rec(i+1, 2));
    return ret;        
}

int main() {
    FIO;  
    // cin >>t;
    // int cnt=1;
    while(t--){
        cin >>n;
        for(int i = 0; i < n; i++)cin >>a[i] >>b[i] >>c[i]; 
        memset(dp, -1, sizeof(dp));
        cout<<rec(0,0)<<endl; 
    }
    return 0;
}
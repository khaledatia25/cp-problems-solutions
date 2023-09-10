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
ll n,m,k,y;
int t=1;



vector<int>v;
vector<vector<ll>>colors;
ll memo[5003][5003];
ll sol(int i, int prev){
    if(i == n)
        return 0;
    ll& ret = memo[i][prev];
    if(~ret)return ret;

    ret = sol(i+1, prev);
    if(v[i]>=prev)ret = max(ret, 1+sol(i+1, v[i]));
    return ret;
}

int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    
    while(t--){
        cin >>n >>m;
        v = vector<int>(n);
        dbl temp;
        for(int& i : v)cin >>i >>temp;
        vector<ll>dp(n+1, MOD);
        dp[0] = -MOD;
        for(int i = 0; i < n; i++){
            int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            if(dp[j-1]<=v[i] && dp[j] > v[i])
                dp[j] = v[i];
        }
        int ans = 0;
        for(int i = 0; i <= n; i++){
            if(dp[i]<MOD)
                ans = i;
        }
        cout<< n - ans<<endl;
    }
    return 0;
}
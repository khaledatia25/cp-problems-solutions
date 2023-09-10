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
ll inf = 1e9+1;
ll n,m,k,x,y;
int t=1;



vector<int>v;
vector<vector<ll>>colors;
ll dp[109][109][109];

ll rec(ll i,ll prev, ll sum){
    if(sum > k)
        return 1e12;
    if(i == n)
        return (sum == k? 0 : 1e12);
    
    ll &ret = dp[i][prev][sum];
    if(~ret)return ret;

    ret = 1e12;

    if(v[i] != 0){
        ret = rec(i+1, v[i],(v[i] != prev) + sum);
    }else{
        for(int j = 0; j < m; j++){
            v[i] = j+1;
            ret = min(ret,colors[i][j] + rec(i+1, v[i], sum + (v[i] != prev)));
            v[i] = 0;
        }
    }
    return ret;

}

int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(t--){
        cin >>n >>m >>k;
        int x;
        colors = vector<vector<ll>>(n+1,vector<ll>(m+1, 0));
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++)cin >>x, v.push_back(x);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >>colors[i][j];
            }
        }
        ll ans = rec(0,m+5,0);
        cout<<(ans < 1e12? ans:-1)<<endl;

    }
    return 0;
}
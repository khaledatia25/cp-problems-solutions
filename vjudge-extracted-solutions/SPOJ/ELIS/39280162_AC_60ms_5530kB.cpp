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
          
}

int main() {
    FIO;  
    // cin >>t;
    // int cnt=1;
    while(t--){
        cin >>n;
        vector<ll>a(n);
        for(ll &i : a)cin >>i;
        ll inf = 1e9+6;
        vector<ll>dp(n+1, inf);
        dp[0]=-inf;
        for(int i = 0; i < n; i++){
            int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            if(dp[j-1]<a[i] && dp[j]>a[i]){
                dp[j] = a[i];
            }
        } 
        int ans = 0;
        for(int i = 0; i <= n; i++){
            if(dp[i]<inf){
                ans = i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
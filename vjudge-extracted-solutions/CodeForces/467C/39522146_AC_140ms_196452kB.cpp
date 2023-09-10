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
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mkV(v, type, l, i) v=vector<type>(l, i)
#define prefix(a, n) for(int i = 1; i < n; i++)a[i]+=a[i-1]
#define getV(v) for(auto& i : v)cin>>i
#define endl "\n"
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;
ll inf = 1e9+1;
ll n,m,k,y;
int t=1;
ll v[5009]; 

ll dp[5009][5009];
int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(t--){
		cin >>n >>m >>k;
        for(int i = 1; i <= n; i++){
            cin >>v[i];
            v[i]+=v[i-1];
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = k-1; j >= 0 ; --j){
                if(i+m<= n)
                    dp[i][j] = max(dp[i][j], v[i+m]-v[i]+dp[i+m][j+1]);
                dp[i][j] = max(dp[i][j], dp[i+1][j]);    
            }
        }    

        cout<<dp[0][0]<<endl;

    }
    return 0;
}
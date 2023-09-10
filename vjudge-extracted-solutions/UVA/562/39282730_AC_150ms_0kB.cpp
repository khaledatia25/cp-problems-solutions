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

ll n,m,k;
int t=1;
int a[100009];
ll dp[101][50001];
const int N = 100005;
int all = 0;
int rec(int i, int sum){
    if(i == n){
        return abs(all-2*sum);
    }
    ll &ret = dp[i][sum];
    if(~ret)return ret;

    ret = min(rec(i+1, sum), rec(i+1, sum+a[i]));
    return ret;
}

int main() {
    FIO;  
    cin >>t;
    // int cnt=1;
    while(t--){
        cin >>n;
        all = 0;
        for(int i = 0; i < n; i++){
            cin >>a[i];
            all+=a[i];
        }
        memset(dp, -1, sizeof(dp));
        cout<<rec(0, 0)<<endl;    

    }
    return 0;
}
/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define endl "\n"
using namespace std;


/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
ll dp[100005];
int arr[100005];
int n;
ll frog(int i){
    if(i == n-1)
        return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i] = 1e9;    
    dp[i] = min(dp[i],frog(i+1) + abs(arr[i+1]-arr[i]));
    if(i+2<=n-1)dp[i] = min(dp[i], frog(i+2)+abs(arr[i+2]-arr[i]));
    return dp[i];
}


void solve(int cnt){
    cin >>n;
   for(int i = 0; i < n; i++){
        cin>>arr[i];
   }
   memset(dp,-1,sizeof(dp));
   cout<<frog(0)<<endl;
    
}   

int t=1;
int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(t--){
       solve(cnt++);

    }
    return 0;
}
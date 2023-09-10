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
const int N = 100005;

int n,m;
string s1, s2;

int summ = 0;
string s;
int grid[1008][1008];
int arr[1002];
int dp[105][105];
int rec(int i,int j){
    if(i == n||j==m)
        return 0;

    if(dp[i][j] != -1)return dp[i][j];
    if(i+1<=n && j+1<= m){
        dp[i][j] = max(rec(i+1, j)+grid[i][j], rec(i+1, j+1)+grid[i][j]);
    }
    if(i+1<= n&& j-1>=0){
        dp[i][j] = max(dp[i][j], rec(i+1, j-1)+grid[i][j]);
    }
    return dp[i][j];
}

void solves(int ttt){
    cin >>n >>m;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
                cin >>grid[i][j];
    int ans = 0;
    for(int i = 0; i < m; i++)
        ans=max(ans, rec(0,i));            
    cout<<ans<<endl;                
   
}   

int t=1;
int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    while(t--){
       solves(cnt++);

    }
    return 0;
}
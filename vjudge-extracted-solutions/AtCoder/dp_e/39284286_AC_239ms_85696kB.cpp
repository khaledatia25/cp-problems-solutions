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
const int N = 100005;

ll a[N], w[N], dp[105][N];
int n, W;
int arr[1000005];
int freq[1000008];
int summ = 0;
ll rec(int i, ll sum){
    if(i == n){
        if(sum == 0)return 0;
        else return 1e9;
    }
    if(dp[i][sum] != -1)return dp[i][sum];
    if(sum-a[i]>= 0)dp[i][sum]=min(rec(i+1, sum-a[i])+w[i], rec(i+1, sum));
    else dp[i][sum] = rec(i+1, sum);    
    return dp[i][sum];    
}
void solve(int cnt){
    cin >>n >>W;
    for(int i = 0; i < n; i++)cin >>w[i]>>a[i], summ += a[i];
    memset(dp,-1,sizeof(dp));
    for(int i = summ; i >= 0; i--){
        if(rec(0, i) <= W){
            cout<<i<<endl;
            return;
        }

    }
    

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
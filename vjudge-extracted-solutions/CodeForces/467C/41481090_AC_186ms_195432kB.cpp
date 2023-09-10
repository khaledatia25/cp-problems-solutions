#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};     
int main() {
    KHALED_WALEED_ATTIA
    /*
        F(i) =  
    
    */
    int n, m, k;
    cin >>n >>m >>k;
    ll salaries[n+1];
    salaries[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >>salaries[i];
        salaries[i] += salaries[i-1];
    }
    ll dp[n+1][k+1];
    memset(dp,0,sizeof dp);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            ll ch =  i>= m ? salaries[i] - salaries[i-m] + dp[i-m][j-1] : 0;
            dp[i][j] = max(dp[i][j], ch);
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
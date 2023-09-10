#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

int main() {
    KHALED_WALEED_ATTIA
    int l;
    while(cin >>l, l){
        int n;
        cin >>n;
        int cuts[n+2];
        for(int i = 1; i <= n; i++)
            cin >>cuts[i];
        int dp[n+2][n+2];
        cuts[0] = 0;
        cuts[n+1] = l;
        memset(dp, 0, sizeof dp);
        for(int ci = n-1; ci >= 0; ci--){
            for(int cj = ci+2; cj < n+2; cj++){
                dp[ci][cj] = INT_MAX;
                for(int k = ci+1; k < cj; k++){
                    dp[ci][cj] =  min(dp[ci][cj], (cuts[cj] - cuts[ci]) + dp[k][cj] + dp[ci][k]);
                }
            }
        }
        cout<<"The minimum cutting is ";
        cout<<dp[0][n+1]<<"."<<endl;
    }
    return 0;
}











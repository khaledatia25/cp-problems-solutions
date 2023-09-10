#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;



int main() {
    KHALED_WALEED_ATTIA
    int n;
    cin >>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >>arr[i];

    ll dp[n][n];
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i==j){
                dp[i][j] = 0;
                // continue;
            }else{
                ll sum = 0;
                for(int k = i; k <= j; k++)
                    sum += arr[k];
                dp[i][j] = 1e15L+5;
                for(int k = i; k <= j-1; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum);
                }
            
        }
    }
    cout<<dp[0][n-1]<<endl;

    return 0;
}
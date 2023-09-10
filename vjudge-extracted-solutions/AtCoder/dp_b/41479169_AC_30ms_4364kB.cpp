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
    F(i) = max(
        |h[i]-h[i+1]| + F(i+1), 
        |h[i]-h[i+2]| + F(i+2),
        .
        .
        . 
        |h[i]-h[i+k]| + F(i+k) 
    );
    i == n-1  F(i) = 0
   */
    int n, k;
    cin >>n >>k;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >>h[i];
    }
    int dp[n];
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        dp[i] = INT_MAX;
        for(int j = i+1; j <= min(n-1, i+k);j++){
            dp[i] = min(dp[i], abs(h[i] - h[j]) + dp[j]);
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}
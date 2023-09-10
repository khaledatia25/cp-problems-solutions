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
    int n,t;
    cin >>n >>t;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++)
        cin >>a[i].first >>a[i].second;
    int dp[n+1][t+1];
    sort(a, a+n);
    for(int i = n; i >= 0; i--){
        for(int rem = 0; rem <= t; rem++){
            if(i == n||rem == 0){
                dp[i][rem] = 0;
            }else{
                dp[i][rem] = dp[i+1][rem];
                dp[i][rem] = max(dp[i][rem], dp[i+1][max(0,rem - a[i].first)] + a[i].second);
                
            }
        }
        
    }
    cout<<dp[0][t]<<endl;
    return 0;
}
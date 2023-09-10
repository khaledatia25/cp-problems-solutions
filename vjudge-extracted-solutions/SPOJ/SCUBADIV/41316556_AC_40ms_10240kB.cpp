#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;

int main() {
    KHALED_WALEED_ATTIA
    int tt;
    cin >>tt;
    int t, a, n;
    while(tt--){
        cin >>t >>a;
        cin >>n;
        int o[n], ni[n], w[n];
        for(int i = 0; i < n; i++)
            cin >>o[i] >>ni[i] >>w[i];
            
        int dp[n+1][t+1][a+1];
        for(int i = n; i >= 0; i--){
            for(int o_needed = 0; o_needed <= t; o_needed++){
                for(int ni_needed = 0; ni_needed <= a; ni_needed++){
                    if(o_needed == 0 && ni_needed == 0){
                        dp[i][o_needed][ni_needed] = 0;
                        continue;
                    }
                    if(i == n){
                        dp[i][o_needed][ni_needed] = 1e7+1;
                        continue;
                    }
                    int ch1 = dp[i+1][o_needed][ni_needed];
                    int ch2 = w[i] + dp[i+1][max(o_needed - o[i], 0)][max(0, ni_needed - ni[i])];
                    dp[i][o_needed][ni_needed] = min(ch1, ch2);
                }
            }
        }
        
        cout<<dp[0][t][a]<<endl;
    }
    return 0;
}
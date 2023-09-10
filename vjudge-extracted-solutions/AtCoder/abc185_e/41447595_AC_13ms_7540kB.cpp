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
    int t = 1;
    // cin >>t;
    while(t--){
        int n, m;
        cin >>n >>m;
        vector<int>a(n), b(m);
        for(int &i : a) cin >>i;
        for(int &j : b) cin >>j;
        int dp[n+1][m+1];
        for(int i = n; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                if(i == n){
                    dp[i][j] = m-j;
                }else if(j == m){
                    dp[i][j] = n-i;
                }else{
                    int ch1 = INT_MAX, ch2 = INT_MAX, ch3 = INT_MAX;
                    if(a[i] == b[j]){
                        ch1 = dp[i+1][j+1];
                    }else {
                        ch1 = 1+dp[i+1][j+1];
                        ch2 = 1+dp[i][j+1];
                        ch3 = 1+dp[i+1][j];
                    }
                    dp[i][j] = min({ch1,ch2,ch3});
                }
            }
        }
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
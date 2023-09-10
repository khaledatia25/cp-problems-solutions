#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

int main() {
    KHALED_WALEED_ATTIA
    int t;
    cin >>t;
    while(t--){
        string s;
        cin >>s;
        int n = s.size();
        ll dp[n+1];
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--){
            string num = "";
            dp[i] = INT_MIN;
            for(int k = i; k < min(i+10, n); k++){
                num += s[k];
                ll numnum = stoll(num);
                if(numnum<=INT_MAX)
                    dp[i] = max(dp[i], numnum + dp[k+1]);
                else
                    break;
            }
        }
        cout<< dp[0]<<endl;
    }

    return 0;
}
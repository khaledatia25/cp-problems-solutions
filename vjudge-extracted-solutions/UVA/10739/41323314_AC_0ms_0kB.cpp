#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

int main() {
    KHALED_WALEED_ATTIA
    int t;
    cin >>t;
    int Case = 1;
    while(t--){
        string s;
        cin >>s;
        int dp[s.size()][s.size()];
        for(int i = s.size() - 1; i >=0; i--){
            for(int j =0; j < s.size(); j++){
                if(i>=j){
                    dp[i][j] = 0;
                    continue;
                }
                int ch1 = dp[i+1][j-1] + (s[i] != s[j]);
                int ch2 = dp[i+1][j] + 1;
                int ch3 = dp[i][j-1] + 1;
                dp[i][j] = min({ch1, ch2, ch3});
            }
        }
        cout<<"Case "<<Case++<<": ";
        cout<<dp[0][s.size() - 1]<<endl;
    }
    return 0;
}

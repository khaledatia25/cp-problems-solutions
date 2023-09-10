#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;

int main() {
    KHALED_WALEED_ATTIA
    string s, t;
    /*
        F(i, j) -> F(i, j+1)
                -> F(i+1, j)
                -> 1 + F(i+1, j+1) condition s[i] == t[j]

        F(i, j) = 0    i == s.size() || j == t.size()
    */
    cin >>s >>t;
    int dp[s.size() + 1][t.size() + 1];
    for(int i = s.size(); i >= 0; i--){
        for(int j = t.size(); j >= 0; --j){
            if(i == s.size() || j == t.size()){
                dp[i][j] = 0;
                continue;
            }
            int ch1 = dp[i][j+1];
            int ch2 = dp[i+1][j];
            int ch3 = 0;
            if(s[i] == t[j])
            ch3 = 1 + dp[i+1][j+1];

            dp[i][j] = max({ch1, ch2, ch3});
        }
    }
    int ans =  dp[0][0];
    string answer = "";
    int i = 0, j = 0;
    while(i!=s.size() && j !=t.size()){
        if(s[i] == t[j]){
            answer.push_back(s[i]);
            i++;
            j++;
        }else{
            if(dp[i+1][j] > dp[i][j+1]){
                i++;
            }else{
                j++;
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}
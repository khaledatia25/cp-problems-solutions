#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
void fileInput();
const int N = 10000000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
const ll mod = 1000000000;
ll modular_expo(ll x, ll n, ll m){
    ll res = 1;
    while(n>0)
    {
        if(n%2==1)
            res = ( ( res % m ) * ( x % m ) ) % m;
        x = ( ( x % m ) * ( x % m ) ) % m;
        n = n / 2;
    }
    return res%m;
}
int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    string s;
    while(cin >>s){
        ll dp[s.size()][s.size()];
        memset(dp, 0, sizeof dp);
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }
                if(s[i] != s[j]){
                    dp[i][j] = 0;
                    continue;
                }
                for(int k = i+2; k <= j; k++){
                    if(s[i] == s[k])
                        dp[i][j] = (dp[i][j]%mod + dp[i+1][k-1]%mod * dp[k][j]%mod)%mod;
                }
            }
        }
        cout<<dp[0][s.size()-1]<<endl;
    }

    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
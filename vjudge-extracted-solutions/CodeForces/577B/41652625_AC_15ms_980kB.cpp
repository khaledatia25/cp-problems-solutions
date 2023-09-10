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

int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int n, m;
    cin>>n>>m;
    if(n>=m){
        cout<<"YES"<<endl;
        return 0;
    }
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >>v[i];
    }
    bool dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    for(int i = n; i >= 0; i--){
        for(int rem = 0; rem <= m  ; rem++){
            if(i == n){
                dp[i][rem] = rem == 0 ? 1 : 0;
                continue;
            }
            dp[i][rem] = dp[i+1][rem] || dp[i+1][(rem + v[i])%m];
        }
    }
    if(dp[0][m])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
void fileInput();
const int N = 1000000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
const ll mod = 1000000007;


ll nCr(ll n, ll r){
    if(n<r)
        return 0;
    ll ans = 1;
    ll d = 1, rem; // r!
    r = max(r, n-r);
    for (ll i = r + 1; i <= n; i++){
        rem = ans % d;
        ans = ans / d * i + rem * i /d;
        d++;
    }
    return ans;
}


int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int n;
    cin >>n;
    char grid[n][n];
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; ++j) {
            cin >>grid[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if(grid[i][j] == 'C')
                cnt++;
        }
        ans += nCr(cnt, 2);
    }
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if(grid[j][i] == 'C')
                cnt++;
        }
        ans += nCr(cnt, 2);
    }
    cout<<ans<<endl;
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
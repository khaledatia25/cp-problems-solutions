#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  double
#define int long long
using namespace std;
void fileInput();
const int N = 6000000+9;
int dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, 1, -1};

const ll mod = 998244353;
ll nCr(ll n, ll r){
    ll ans = 1;
    ll d = 1; // r!
    for (int i = r + 1; i <= n; i++){
        ans = ans * i;
        ans /= d;
        d++;
    }
    return ans;
}
long double c[103][103];
int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    int t = 1;
//    cin >>t;
    int m, w, n;
    for(int i = 0; i <= 100; i++){
        c[i][0] = 1;
    }
    for(int i = 1; i <= 100; i++){
        for (int j = 1; j <= 100; ++j) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    sol = [&](int test) -> void {
        double pm = double(m)/double(m+w);
        double pw = 1.0 - pm;
        double ans = 0.0;
        for(int i = 0; i <= n; i+=2){
            ans += c[n][i] * pow(pm, i) * pow(pw, n - i);
        }
        cout<<fixed<<setprecision(7)<<ans<<endl;
    };
    int test = 1;
    while(1){
        cin >>m >>w >>n;
        if(!w&&!m)return 0;
        sol(test++);
    }

    return 0;
}
/*

 */


void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
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
const ll mod = 1000000007;
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
    int n, m;
    cin >>n >>m;
    vector<string>v(n);
    for(int i = 0; i < n;i++){
        cin >>v[i];
    }
    ll ans = 1;
     for(int j = 0; j < m; j++){
         set<char>st;
         for(int i = 0; i <n ; i++){
             st.insert(v[i][j]);
         }
         ans = (ans%mod * st.size()%mod)%mod;
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
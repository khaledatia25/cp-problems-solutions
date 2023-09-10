#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;


const ll mod = 1000000007;

ll modular_expo(ll x, ll n, ll m = 10000000000000000){
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
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    string first, second;
    while(getline(cin, first), getline(cin, second)){
        vector<int>c, x;
        stringstream s1(first);
        int num;
        while(s1>>num)c.push_back(num);
        stringstream s2(second);
        bool l=0;
        while(s2>>num){
            ll ans = 0;
            for(int i = 0; i < c.size(); i++){
                ans += c[i]*modular_expo(num, c.size() - i -1);
            }
            if(l)cout<<space;
            l=1;
            cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

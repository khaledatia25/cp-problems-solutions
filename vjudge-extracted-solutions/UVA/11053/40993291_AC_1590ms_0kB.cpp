#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;


const ll mod = 1000000007;

int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    ll n, a, b;
    while(cin >>n, n){
        cin >>a >>b;
        map<ll, int>mp;
        ll cur = 0, ans = n;
        mp[cur]++;
        while(true){
            cur = (a%n * (cur%n * cur%n)%n + b)%n;
            mp[cur]++;
            if(mp[cur] == 2)ans--;
            else if(mp[cur] == 3)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

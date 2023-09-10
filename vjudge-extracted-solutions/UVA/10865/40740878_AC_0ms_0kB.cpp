#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
typedef vector<vector<ll>>GRAPH;

const ll mod = 1000000007; 
int main() {
    KHALED_WALEED_ATTIA
    ll n;
    while(cin >>n,n){
        vector<pair<ll, ll>>v(n);
        for(ll i = 0; i<n; i++){
            cin >>v[i].first >>v[i].second;
        }
        ll mid = n/2;
        ll a=0, b=0;
        for(ll i = 0; i < n; i++){
            ll x = v[i].first - v[mid].first;
            ll y = v[i].second - v[mid].second;
            if(x==0||y==0)continue;
            if(x*y>0)a++;
            else b++;
        }
        cout<<a<<space<<b<<endl;
        
    }
    return 0;
}



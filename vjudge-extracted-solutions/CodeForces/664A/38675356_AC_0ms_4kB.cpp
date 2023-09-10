/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

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

ll big_int_mod(string s,ll MOD){
    ll ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret = ret*10 + (s[i] - '0');
        ret = (ret%MOD);
    }
    return ret;
}
void solve(int n){
    
}
int main() {
    FIO;
    ll t = 1,n,m;
    while(t--){
        string s1,s2;
        cin >>s1 >>s2;
        if(s1 == s2)cout<<s1;
        else cout<<1;
    }
            

    return 0;
}



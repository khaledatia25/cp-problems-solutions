/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define endl "\n"
using namespace std;


/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
ll modular_expo(ll base, ll power, ll mod){
    ll res = 1;
    while(power>0){
        if(power&1)
            res = ( (res%mod) * (base%mod) )%mod;
        base = ((base%mod)*(base%mod))%mod;
        power >>=1; 
    }
    return res%mod;
}

ll modular_factorial(ll n,ll mod){
    ll res = 1;
    for(ll i = 2; i<=n;i++)
        res = (res*i)%mod;
    return res%mod;    
}
vector<ll>factorials(1000009,1);
void calc_factorials(){
    ll res = 1;
    for(ll i = 2; i <= 1000002;i++){
        res = ((res%MOD)*(i%MOD))%MOD;
        factorials[i] = res;
    }
}
ll mod_inverse(ll a, ll mod){
    // only when mod is prime
    return modular_expo(a,mod-2LL,mod);
}
ll modular_compination(ll n, ll r, ll mod){
    ll ans =  (factorials[n]*mod_inverse(factorials[n-r],mod))%mod;
     ans = (ans * mod_inverse(factorials[r],mod))%mod;
    return ans%mod;
}
bool is_beautiful(ll n, int a, int b){
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++){
        if(!( s[i] == ('0'+a) || s[i] == '0'+b))
            return 0;
    }
    return 1;
}
ll gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b, a%b);    
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
bool is_prime(ll n){
    if(n == 2)
        return 1;
    if(n == 1 || n%2 == 0)
        return 0;
    for(ll i = 3; i*i <= n; i+=2){
        if(n%i==0)
            return 0;
    }
    return 1;
}
ll n,t=1,m,sum = 0;
vector<ll>fib(51,0);
void solve(){
    ll a, b, ans = 0;
    cin >>a >>b >>n;
    // factorials pre calculation to avoid time limit 
    calc_factorials();
    for(int i = 0; i <= n; i++){
        sum = i*a+(n-i)*b;
        if(is_beautiful(sum, a, b)){
            ans = (ans%MOD+modular_compination(n,i,MOD)%MOD)%MOD;
        }
    }
    cout<<ans<<endl;
}
int main() {
    FIO;  
    // cin >>t;
    while(t--){
       solve();
    }
    return 0;
}



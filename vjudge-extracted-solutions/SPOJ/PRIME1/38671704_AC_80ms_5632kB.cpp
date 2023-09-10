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


const ll N = 1e6+10;
int a[N];
vector<int>primes;
bool notPrime[N];
void sieve(){
    notPrime[0] = notPrime[1] = 1;
    for(ll i = 2; i*i < N; i++){
        if(!notPrime[i]){
            for(ll j = i*i;j<N;j+=i){
                    notPrime[j] = 1;
            }
        }
    }
}
void linear_sieve(){
    notPrime[0] = notPrime[1] = 1;
    for(ll i = 2; i < N; i++){
        if(!notPrime[i]){
            primes.push_back(i);
        }
        for(ll j = 0; j < primes.size() and i * primes[j] < N; j++){
            notPrime[primes[j]*i] = 1;
            if(i%primes[j] == 0)break;
        }
    }
}
vector<bool> seg_sieve(ll L, ll R){
    ll lim = sqrt(R);
    vector<bool>mark(lim+1, 0);
    vector<ll>primes;
    for(ll i = 2; i <= lim; i++){
        if(!mark[i]){
            primes.emplace_back(i);
            for(ll j = i*i; j <= lim; j+=i){
                mark[j] = 1;
            }
        }
    }
    vector<bool>composite(R-L+1,0);
    for(ll i : primes){
        for(ll j = max<ll>(i*i, (L+i-1)/ i * i );j<=R;j+=i){
            composite[j-L] = 1;
        }
    }
    if(L==1)composite[0]=1;
    return composite;
}
void solve(){
    
    ll n,m;
    cin >>n >>m;
    vector<bool>composite = seg_sieve(n,m);
    for(ll i = 0; i < composite.size(); i++){
        if(!composite[i])
            cout<<i+n<<endl;
    }
    cout<<endl;
}
int main() {
    FIO;
    int t = 1;
    cin >>t;
    while(t--)
        solve();    

    return 0;
}



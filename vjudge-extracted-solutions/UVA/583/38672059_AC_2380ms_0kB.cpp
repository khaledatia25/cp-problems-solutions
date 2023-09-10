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


const ll N = 1e5+10;
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
void solve(int n){
    int x = abs(n);
    cout<<n<<" = ";
    if(n<0)
        cout<<"-1 x ";
    vector<int>divisors;    
    for(int i : primes){
        while(x%i==0){
            divisors.push_back(i);
            x /= i;
        }
    }
    if(x > 1)
        divisors.push_back(x);
    for(int i = 0; i < divisors.size(); i++){
        cout<<divisors[i];
        if(i < divisors.size() - 1)cout<<" x ";
    }
    cout<<endl;
}
int main() {
    FIO;
    int t = 1,n;
    linear_sieve();
    while(cin >>n && n)
        solve(n);    

    return 0;
}



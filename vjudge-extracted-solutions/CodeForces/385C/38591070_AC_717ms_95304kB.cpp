//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define MOD 1000000007
#define dbl double
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

int t =1,n,m=1, arr[25];

bool is_prime(int n){
    if(n == 2)
        return 1;
    if(n == 1 || n%2 == 0)
        return 0;
    for(int i = 3; i*i <= n; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
void prime_factorization(int n, vector<int> &v){
    for(int i = 2; i*i<=n;i++){
        while(n%i==0){
            v.push_back(i);
            n /=i;
        }
    }
    if(n!=1)
        v.push_back(n);

}
const int N = 10000007;
bool composite[N];
void sieve(vector<int>&primes){
    composite[0]=composite[1]=1;
    for(ll i = 2; i*i < N; i++){
        if(!composite[i]){
            for(ll j = i*i;j<N;j+=i){
                composite[j]=1;
            }
        }
    }
    for(int i = 2; i<N; i++){
        if(!composite[i])
            primes.push_back(i);
    }
}
int a[N]={0};
int x[N];
void solve() {
    cin >>n;
    vector<int>primes;
    for(int i = 0; i < n; i++)cin >>m,x[m]++;
    sieve(primes);
    for(int i : primes){
        for(int j = i;j<N;j+=i){
                a[i]+=x[j];
        }
    }
    a[1]=0;
    for(int i = 2;i<N;i++)a[i] += a[i-1];
    int tt;
    cin >>tt;
    int l, r;
    while(tt--){
        cin >>l >>r;
        r = min(r, N-1);
        l = min(l-1,N-1);
        cout<<a[r]-a[l]<<endl;
    }
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
//    cin >>t;
    while (t--){
        solve();
    }

//    fclose(stdout);
    return 0;
}



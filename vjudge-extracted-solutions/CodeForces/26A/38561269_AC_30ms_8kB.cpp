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

ll t =1,n,m=1, arr[25];

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
int prime_factorization(int n){
    set<int>primes;
    for(int i = 2; i*i<=n;i++){
        while(n%i==0){
            primes.insert(i);
            n /=i;
        }
    }
    if(n!=1)
        primes.insert(n);
    return primes.size();
}
void solve() {
    cin >>n;
    int cnt = 0;
    for(int i = 2; i <=n; i++){
        if(prime_factorization(i) == 2)
            cnt++;
    }
    cout<<cnt;
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



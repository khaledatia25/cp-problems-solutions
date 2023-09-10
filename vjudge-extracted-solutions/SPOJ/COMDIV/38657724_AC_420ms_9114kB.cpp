//// To infinity and beyond
#include <bits/stdc++.h>
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/


const int N = 1e6+1;
int a[N];
vector<int>primes;
int num_factors[N];
void sieve(){
    for(int i = 1; i<N;i++)num_factors[i]=1;
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j+=i)num_factors[j]++;
    }
}
void solve(){
    
    int n,m;
    scanf("%d%d",&n,&m);
    int x = __gcd(n,m);
    printf("%d\n",num_factors[x]);
    
    
}
int main() {
    FIO;
    int t = 1;
    scanf("%d", &t);
    sieve();
    while(t--)
        solve();    

    return 0;
}



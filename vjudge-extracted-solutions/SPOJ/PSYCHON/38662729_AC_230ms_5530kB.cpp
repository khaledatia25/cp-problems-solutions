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


const int N = 1e4+4;
int a[N];
vector<int>primes;
int notPrime[N];
void solve(){
    
    int n;
    scanf("%d",&n);
    if(n == 0 || n == 1){
        printf("Ordinary Number\n");
        return;
    }
    int even=0,odd=0;
    for(int i = 2; i*i <= n;i++){
        int cnt = 0;
        while(n%i == 0){
            cnt++;
            n /= i;
        }
        if(cnt){
            if(cnt&1)odd++;
            else even++;
        }
    }
    if(n!=1)odd++;
    if(even>odd)
        printf("Psycho Number\n");
    else
        printf("Ordinary Number\n");
}
int main() {
    FIO;
    int t = 1;
    scanf("%d", &t);
    while(t--)
        solve();    

    return 0;
}



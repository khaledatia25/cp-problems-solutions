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
const int N = 1e7+5;
bool composite[N]={0};
int prevPrimes[N];
void sieve(){
    composite[0]=composite[1]=1;
    for(int i = 2; i*i < N;i++){
        if(!composite[i]) {
            for (int j = i * i; j < N; j += i) {
                composite[j] = 1;
            }
        }
    }
    prevPrimes[0]=prevPrimes[1]=0;
    prevPrimes[2]=2;
    int p = 3;
    for(int i = 3; i< N;i++){
        if(composite[i])
            prevPrimes[i] = p;
        else {
            prevPrimes[i] = i;
            p = i;
        }
    }
}

void solve(int n) {
    if(n<8) {
        cout << "Impossible." << endl;
        return;
    }
    for(int i = 3; i >= 0;i--){
        int lastPrime = prevPrimes[n - (i*2)];
        cout<<lastPrime<<space;
        n-=lastPrime;
    }
    cout<<endl;
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
//    cin >>t;
    sieve();
    while (cin >>n){
        solve(n);
    }

//    fclose(stdout);
    return 0;
}



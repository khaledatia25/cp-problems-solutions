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
const int N = 1e6+2;
void prime_factorization(int n,int &cnt){
    for(int i = 2; i*i<=N;i++){
        while(n%i==0){
            cnt++;
            n /=i;
        }
    }
    if(n!=1)
        cnt++;
}
int ans[N];
void solve(int n) {
    cout<<ans[n]<<endl;
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
//    cin >>t;
    for(int i = 2; i < N;i++){
        int cnt = 0;
        prime_factorization(i,cnt);
        ans[i]=cnt;
    }
    for(int i = 2;i<N;i++)ans[i]+=ans[i-1];
    while (cin >>n){
        solve(n);
    }

//    fclose(stdout);
    return 0;
}



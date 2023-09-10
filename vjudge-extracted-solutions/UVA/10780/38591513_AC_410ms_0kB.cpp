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
void prime_factorization(int n,map<int, int>&mp){
    for(int i = 2; i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n /=i;
        }
    }
    if(n!=1)
        mp[n]++;
}

void solve(int cnt) {
    cin >>m >>n;
    map<int, int>factorial;
    for(int i = 1; i <=n;i++){
        prime_factorization(i,factorial);
    }
    map<int, int>number;
    prime_factorization(m,number);
    int ans = INT_MAX;
    for(auto factor : number){
        ans=min(ans, factorial[factor.first]/factor.second);
    }
    cout<<"Case "<<cnt<<":\n";
    if(ans <=0)
        cout<<"Impossible to divide"<<endl;
    else
        cout<<ans<<endl;
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
    cin >>t;
    int cnt = 1;
    while (t--){
        solve(cnt++);
    }

//    fclose(stdout);
    return 0;
}



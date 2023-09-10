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

ll t =1,n,m, arr[25];



void solve() {
    cin >>n;
    ll sum = 0;
    for(ll i = 1; i*i<=n; i++){
        if(n%i==0){
            sum += i;
           if(i != n/i)
            sum += (n/i);
        }
    }
    sum -= n;
    cout<<sum<<endl;

}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
    cin >>t;
    while (t--){
        solve();
    }

//    fclose(stdout);
    return 0;
}



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

int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(a, a%b);    
}
void solve(){
    
    int n,m;
    scanf("%d%d", &n, &m);
    int x = __gcd(n,m);
    int ans = 0;
    for(ll i = 1; i*i <= x;i++){
        if(x%(int)i==0)
            ans += (x/(int)i == i ? 1 : 2);    
    }
    printf("%d\n",ans);
}
int main() {
    FIO;
    int t = 1;
    scanf("%d", &t);
    while(t--)
        solve();    

    return 0;
}



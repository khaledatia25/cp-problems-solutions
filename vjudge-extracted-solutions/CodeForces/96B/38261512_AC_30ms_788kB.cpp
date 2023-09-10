//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
#define mx_str "99999999999999999999999999"
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/


ll t=1, n, max_weight = 13;
int a[100005], b[100005];

ll p(ll n,int val = 0, ll num = 0){
    if(val == 0 && num >= n)
        return num;
    if(num > 10e11)
        return INT64_MAX;
    return min<ll>(p(n,val+1, num*10+4), p(n,val-1,num*10+7));

}
int main() {
    init();
//    cin >>t;
    while(t--){
        cin >>n;
        cout<<p(n);
    }

    return 0;
}


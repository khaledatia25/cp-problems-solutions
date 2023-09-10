//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

ll t=1, n,x, max_weight = 13,m;
vector<vector<ll>>v;
ll sum = 0;
void p(ll idx,ll res=1){
    if(idx >= n){
        if(res == m)sum++;
        return;
    }
    for(ll a : v[idx]){
        if(res > m/a)continue;
        p(idx+1,res*a);
    }
}

int main() {
    init();
//    cin >>t;
    while(t--){
        cin >>n >>m;
        for(int i = 0; i < n; i++){
            ll j;
            cin >>j;
            vector<ll>vv(j);
            for(ll &k : vv)cin >>k;
            v.push_back(vv);
        }

        p(0);
        cout<<sum;

    }

    return 0;
}




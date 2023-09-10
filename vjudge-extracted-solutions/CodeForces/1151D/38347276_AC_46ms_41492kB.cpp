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

int t=1, n,x, max_weight = 13,m;
vector<vector<ll>>v;
ll sum = 0;
int a[10000009] = {0};

bool p(int idx,ll sum){
    if(idx == n)
        return (sum==m);
    return p(idx+1, sum+a[idx])|| p(idx+1, sum-a[idx]);
}
vector<int> friends;
int main() {
    init();
//    cin >>t;
    while(t--){
        cin >>n;
        vector<pair<ll, pair<ll, ll>>>v(n);
        for(int i = 0; i < n; i++){
            ll a,b;
            cin >>a >>b;
            v[i] = make_pair(a-b, make_pair(a,b));
        }
        sort(v.rbegin(),v.rend());
        ll ans = 0;
        for(int i= 0; i<n;i++){
            ans += (v[i].first*(i+1)+v[i].second.second*n-v[i].second.first);
        }
        cout<<ans;

    }

    return 0;
}



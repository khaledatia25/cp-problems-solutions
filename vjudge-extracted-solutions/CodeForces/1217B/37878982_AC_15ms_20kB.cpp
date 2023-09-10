// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
bool pred(ll n, ll d, ll h, ll x, ll mx){
    return (n - 1) * d  + mx >= (n - 1) * h + x;
}
//I love binary search !
ll BS( ll d, ll h, ll x, ll mx){
    ll lo = 1, hi = 1e10, mid, ans = -1;
    while (lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(pred(mid,d,h,x, mx)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return ans;
}
int main() {
    init();
    int t;cin >>t;
    while(t--){
        ll n, x;
        cin >>n >>x;
        vector<pair<ll,pair<ll,ll>>>v;
        ll mx = INT_MIN;
        bool ee = false;
        for(int i = 0; i < n; i++){
            ll d, h;
            cin >>d >>h;
            if(d >= x)ee= true;
            mx = max<ll>(mx,d);
            if(d >= h)
                v.emplace_back(d-h, make_pair(d,h));
        }
        if(ee){cout<<1<<endl; continue;}
        if(v.empty()){cout<<-1<<endl; continue;}
        sort(v.rbegin(), v.rend());
        cout<<BS(v[0].second.first, v[0].second.second, x, mx)<<endl;

    }
    return 0;
}








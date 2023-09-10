#include <bits/stdc++.h>
#include <string>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0);
using namespace std;
void init(){fast;}
using ll =  long long;
ll   n,  t, sum = 0,   xi, yi, k, s, q;
ll pred(vector<ll> h, vector<ll> c,ll k){
    ll total_cost = 0;
    for(int i = 0; i < h.size(); i++){
        total_cost += (abs(h[i] - k) * c[i]);
    }
    return total_cost;
}
ll BS(vector<ll>h, vector<ll>c){
    ll lo = 0, hi = 1e+4 + 4;
    ll mid1, mid2, ans1, ans2, ans;
    while (lo <= hi){
        mid1 = lo + (hi - lo) / 3;
        mid2 = hi - (hi - lo) / 3;
        ans1 = pred(h,c,mid1);
        ans2 = pred(h, c, mid2);
        if(ans1 >= ans2){
            ans = ans1;
            lo = mid1 + 1;
        } else {
            hi = mid2 - 1;
        }
    }
    return ans;
}
int main() {
    init();
    cin >>t;
    while (t--){
        cin >>n >>q;
        vector<ll>candies(n), c(n + 1, 0);
        for(int i = 0; i < n; i++) cin>>candies[i];
        sort(candies.rbegin(), candies.rend());
        for(int i = 1; i <= n; i++) c[i] = c[i-1] + candies[i - 1];
        while (q--){
            cin >>xi;
            auto it = lower_bound(c.begin()+1, c.end(), xi);
            if(it == c.end())cout<<-1<<endl;
            else cout<<(int)(it - c.begin())<<endl;
        }
    }
    return 0;
}

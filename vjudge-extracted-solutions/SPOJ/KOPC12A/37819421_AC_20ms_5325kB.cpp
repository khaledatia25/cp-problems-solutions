// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
int n, t;
double  k;
ll h[100005], c[100005];
ll f(ll x){
    ll cost =  0;
    for(int i = 0; i < n; i++){
        cost += (abs(h[i] - x) * c[i]);
    }
    return cost;
}

ll BS(){
    ll lo = 0, hi = 1e5, mid1 , mid2, ans1, ans2, ans;
    while(lo <= hi){
        mid1 = lo + (hi - lo) / 3;
        mid2 = hi - (hi - lo) / 3;
        ans1 = f(mid1);
        ans2 = f(mid2);
        if(ans1 >= ans2){
            ans = ans1;
            lo = mid1 + 1;
        } else {
            hi = mid2 -1;
        }
    }
    return ans;
}
int main() {
    init();
    cin >>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++)cin >>h[i];
        for(int i = 0; i < n; i++)cin >>c[i];
        cout<<BS()<<endl;

    }
    return 0;
}








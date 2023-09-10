// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
double   x, y;
ll t;
double f(double h){
    return (x - 2 * h) * (y - 2 * h) * h;
}

double BS(){
    double lo = 0, hi = x / 2, mid1 , mid2, ans1, ans2, ans;
    while(fabs(hi - lo) > 1e-6){
        mid1 = lo + (hi - lo) / 3;
        mid2 = hi - (hi - lo) / 3;
        ans1 = f(mid1);
        ans2 = f(mid2);
        if(ans1 < ans2){
            lo = mid1;
            ans = ans1;
        } else{
            hi = mid2;
        }
    }
    return ans;
}
int main() {
    init();
    cin >>t;
    while(t--){
        cin >>x >>y;
        cout<<fixed<<setprecision(11)<<BS()<<endl;

    }
    return 0;
}








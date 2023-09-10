// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
double p, q, r, s, t, u;
double f(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double BS(){
    double lo = 0, hi = 1, mid;
    while (fabs(hi - lo) >= 1e-9){
        mid = lo + (hi - lo) / 2;
        if(f(mid) >= 0){
            lo = mid;
        }else {
            hi = mid;
        }
    }
    return mid;
}
int main() {
    init();

    while(cin >>p >>q >>r >>s >>t >>u){
        double x = BS();
        if(fabs(f(x)) <= 1e-4)
            cout<<fixed<<setprecision(4)<<x<<endl;
        else
            cout<<"No solution"<<endl;
    }
    return 0;
}








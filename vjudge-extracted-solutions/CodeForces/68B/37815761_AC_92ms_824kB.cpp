// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
int n;
double  k;
double v[100005];
bool f(double x){
    double trans = 0, need = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > x){ trans += (v[i] - x); }
        else{
            need += (x - v[i]);
        }
    }
    trans -= (trans*k/100);
    return trans >= need;
}

double BS(){
    double lo = 0.0, hi = 1000.0, mid;
    while(fabs(hi - lo) > 1e-10){
        mid = lo + (hi - lo) / 2;
        if(f(mid)){
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}
int main() {
    init();
    cin >>n >>k;
    for(int i = 0; i < n; i++){cin >>v[i];}
    cout<<fixed<<setprecision(9)<<BS();
    return 0;
}








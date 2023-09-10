#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
#define int long long
using namespace std;
void fileInput();
const int N = 6000000+9;
int dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, 1, -1};

const ll mod = 998244353;

int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    int t = 1;
//    cin >>t;
    double cows, cars, open;
    sol = [&](int test) -> void {
        double cnt = cows + cars;
        double  ans = 0;
        // car then cow
        ans += (cars/cnt)*(cars - 1) /(cnt - open - 1);
        // cow then car
        ans += (cows/cnt)*(cars/(cnt - open - 1));
        cout<<fixed<<setprecision(5);
        cout<<ans<<endl;
    };
    int test = 1;
    while(cin >>cows >> cars >>open){
        sol(test++);
    }

    return 0;
}
/*
    
 */


void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
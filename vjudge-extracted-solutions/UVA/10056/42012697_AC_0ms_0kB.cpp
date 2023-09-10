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
    cin >>t;
    sol = [&](int test) -> void {
        double n, i;
        double p;
        cin >>n >>p >>i;
        double ans = 0;
        // p(i wins) = p(first i - 1 lose) * p(win) or p(all loses) * p(i wins)
        // p(i wins) = (1-p)^(i-1) * p + (1-p)^n * p(i wins)
        ans = pow(1.0 - p, i-1.0) * p / (1.0 - pow(1.0 - p, n));
        if(p == 0){
            ans = 0;
        }
        cout<<fixed<<setprecision(4)<<ans<<endl;
    };
    int test = 1;
    while(t--){
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
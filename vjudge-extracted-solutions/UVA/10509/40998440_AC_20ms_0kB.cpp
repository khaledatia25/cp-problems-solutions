#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;


const ll mod = 1000000007;

int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    double n;
    while(cin >>n,n){
        int x = cbrt(n);
        double ans = x;
        ans += (n - ans*ans*ans)/ (3 * ans*ans);
        cout<<fixed<<setprecision(4)<<ans<<endl;
    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

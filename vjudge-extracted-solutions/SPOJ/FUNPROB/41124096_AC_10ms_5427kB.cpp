#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1},
        dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const ll mod = 1000000007;

int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int n, m;
    while(cin >>n>>m, n||m){
        if(n>m){
            cout<<"0.000000"<<endl;
            continue;
        }
        double  ans = double (m-n+1) / double(1+m);
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


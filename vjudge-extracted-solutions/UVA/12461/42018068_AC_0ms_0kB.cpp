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
vector<double>p;
vector<bool>vis;
int n, m;
int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    int t = 1;
//    cin >>t;
    sol = [&](int test) -> void {
        cout<<"1/2"<<endl;

    };
    int test = 1;
    while(cin >>n,n){
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
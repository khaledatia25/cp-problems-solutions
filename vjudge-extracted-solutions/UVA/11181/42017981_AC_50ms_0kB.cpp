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
        p.clear();
        p.resize(n);
        vis = vector<bool>(n, 0);
        for(double  &i : p)
            cin >>i;
        cout<<"Case "<<test<<":"<<endl;
        vector<double>a(n, 0);
        double b = 0;
        for(int i = 0; i < (1<<n); i++){
            if(__builtin_popcount(i) == m){
                double temp = 1;
                bitset<30>u(i);
                for(auto k = 0; k < n; k++){
                    if(u[k]){
                        temp *= p[k];
                    }else{
                        temp *= 1.0-p[k];
                    }
                }
                b += temp;
//                cout<<temp<<endl;
                for(auto k = 0; k < n; k++){
                    if(u[k])
                        a[k] += temp;
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout<<fixed<<setprecision(6)<<a[i]/b<<endl;
        }

    };
    int test = 1;
    while(cin >>n >>m, n!=0||m!=0){
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
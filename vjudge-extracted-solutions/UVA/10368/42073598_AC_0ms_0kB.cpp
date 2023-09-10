#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
#define int long long
using namespace std;
void fileInput();
const int N = 6000000+9;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1},
        dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

const ll mod = 1e9+7;
bool is_prime(int n){
    for(int i = 2; i*i<=n;i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}
bool is_good(int n){
    vector<int>v;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            v.push_back(i);
            if(i*i != n)
                v.push_back(n/i);
        }
    }
    if(v.size() == 2){
        if(is_prime(v[0]) && is_prime(v[1])){
            return 1;
        }
    }else if(v.size() == 1 && v[0]*v[0] == n){
        return 1;
    }
    return 0;
}
int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    int n, m;
    sol = [&](int test) -> void {
        bool s = 0;
        while(n&&m){
            s^=1;
            if(n<m)
                swap(n,m);
            if(n/m > 1)
                break;
            n -= m;
        }
        if(s)
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
    };
    int t = 1;
//    cin >>t;
    int test = 1;
    while(cin >>n >>m,n&&m){
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
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
void fileInput();
const int N = 1000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
const int mod = 1000000000;
int pascal[N][N];
void calcPascal(){
    for(int i = 0; i < N; i++){
        pascal[i][0]=1;
        pascal[i][i]=1;
    }
    for(int i = 1; i < N; i++){
        for(int  j = 0; j < i; j++){
            pascal[i][j] = pascal[i-1][j]%mod + pascal[i-1][j-1]%mod;
            pascal[i][j]%=mod;
        }
    }
}

int32_t main() {
    KHALED_WALEED_ATTIA
//    fileInput();
    calcPascal();
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        for(int i = 0; i <= n; i++)
            cout << pascal[n][i] << space;
        cout<<endl;
    }
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
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
string s1, s2;
int memo[109][50009];
int coins[109];
int m, sum = 0;
int rec(int i,int val){
    if(i == m)
        return abs(sum-2*val);
    int & ret = memo[i][val];
    if(~ret)
        return ret;

    return ret =  min(rec(i+1, val+coins[i]), rec(i+1, val));
}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    cin >>t;
    while(t--){
        cin >>m;
        sum = 0;
        for(int i = 0; i < m; i++){
            cin >>coins[i];
            sum += coins[i];
        }
        memset(memo, -1, sizeof memo);
        cout<<rec(0,0)<<endl;
    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

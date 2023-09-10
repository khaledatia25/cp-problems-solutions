/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define setting(x, i) memset(x, i, sizeof(x))
#define endl "\n"
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;
ll inf = 1e9+1;
ll n,m,k,y;
int t=1;



vector<int>v;
vector<vector<ll>>colors;
ll memo[105][10009];
ll sol(int i, int x){
    if(x<0)
        return -1e12;
    if(i == n)
        return 0;
    ll& ret = memo[i][x];
    if(~ret)return ret;

    ret = max(sol(i+1,x),1+sol(i+1,x - (n-i)*v[i]));
    
    return ret;
}

int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(t--){
        ll x;
        cin >>n >>x;
        v=vector<int>(n);
        setting(memo, -1);
        for(int &i : v)cin >>i;
        cout<<sol(0,x)<<endl;

    }
    return 0;
}
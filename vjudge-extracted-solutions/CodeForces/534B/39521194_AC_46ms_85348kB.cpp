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
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mkV(v, type, l, i) v=vector<type>(l, i)
#define getV(v) for(auto& i : v)cin>>i
#define endl "\n"
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;
ll inf = 1e9+1;
ll n,m,k,y;
int t=1;


int v1, v2, d;
vector<int>v;
vector<int>colors;
ll memo[109][100009];
ll sol(ll i, ll v){
    if(v<0)
        return -1e9+1;
    if(i == n-1){
        if(v == v2)
            return v;
        else 
            return -1e9+1;    
    }
    ll& ret = memo[i][v];
    if(~ret)return ret;
    ret = v+sol(i+1, v);
    for(int k = 1; k <= d; k++){
        ret = max({v+sol(i+1,v+k),v+sol(i+1,v-k), ret});
    }
    return ret;
}   

int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(t--){
		cin >>v1 >>v2;
        cin >>n >>d;
        setting(memo, -1);
        cout<<sol(0,v1)<<endl;
    }
    return 0;
}
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



vector<int>v;
vector<int>colors;
ll memo[10009][22][22];
ll sol(int i, int k1, int k2){
    int j = n - 1-i - k1 + k2;
    if(i>=j)
        return 0;
    if(k1+k2>k)
        return 40;
    ll& ret = memo[i][k1][k2];
    if(~ret)return ret;
    
    if(v[i] == v[j])
        ret = sol(i+1,k1,k2);
    else 
        ret = min(sol(i+1,k1,k2+1)+1, sol(i,k1+1,k2)+1);
    return ret;
}   

int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    while(t--){
        cin >>n >>k;
        mkV(v,int,n,0);
        getV(v);
        setting(memo, -1);
        int ans = sol(0,0,0);
        if(ans == 0)
            cout<<"Case "<<cnt++<<": Too easy"<<endl;
        else if(ans > k)
            cout<<"Case "<<cnt++<<": Too difficult"<<endl;
        else
            cout<<"Case "<<cnt++<<": "<<ans<<endl;

    }
    return 0;
}
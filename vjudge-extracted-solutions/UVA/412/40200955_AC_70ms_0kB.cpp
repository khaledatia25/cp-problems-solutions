/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define setting(x, i) memset(x, i, sizeof(x))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mkV(v, type, l, i) v=vector<type>(l, i)
#define prefix(a, n) for(int i = 1; i < n; i++)a[i]+=a[i-1]
#define getV(v) for(auto& i : v)cin>>i
#define endl "\n"
#define fr(a,b) for(int a=0;a<=b;a++)
#define frh(a,b) for(int a=1;a<=b;a++)
using namespace std;
const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};
const int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;
ll inf = 1e9+1;
ll n,m,k,y;
int t=1; 
const int OO = 0x3f3f3f3f;
const int SZ = 1e5+5;
// int arr[SZ];
set<int>st;
ll x,w, minus, temp,  l, r,d,k1,k2,odd,even;
ll const N = 1e12+1;
ll memo[150][150][150];
int p[150][150];
ll MM = 998244353;
string s;
ll MEMO(int k,int i,int j){   
    // if(k == n)
    //      return 1;
    // ll &ret = memo[k][i][j];
    // if(~ret)
    //     return ret;

    // ret = 0;
    // if(p[i][j] == 1){
    //     for(int m = i+1; m <= j; m++){
    //         if(s[m]!=s[m-1]){
    //             return ret = 0;
    //         }
    //     }
    // }else if(p[i][j] == 2){
    //     for(int m = i+1; m <= j; m++){
    //         if(s[m]!=s[m-1]){
    //             s.push_back('1');
    //             ret += MEMO(k+1,i,j+1)%MM + MEMO(k+1,) 
    //             return ret = 0;
    //         }
    //     }
    // }    

    // return ret % MM;

}
ll nCr(ll n, ll r){
    if(r == 1)
        return n;
    if(r == 0)
        return 1;
    if(r == n)
        return 1;
    return nCr(n-1,r-1) * n / r;            
}
int main() {
    KHALED_WALEED_ATTIA
    // t=26;
    while(cin >>n){
        if(!n)return 0;
        vector<int>v(n);
        getV(v);
        int cnt = 0, p = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                p++;
                if(__gcd(v[i],v[j]) == 1) cnt++;  
            }
        }
        // cout<<cnt<<space;
        if(!cnt){
            cout<<"No estimate for this data set."<<endl;
        }else{
            dbl pi = sqrt((6.0*(dbl)p) / (dbl)cnt);
            cout<<fixed<<setprecision(6)<<pi<<endl;
        }
        

    }
    
    return 0;
}
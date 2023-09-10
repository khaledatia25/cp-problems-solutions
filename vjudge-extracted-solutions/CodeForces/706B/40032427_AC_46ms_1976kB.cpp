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
ll x, minus, temp,  l, r,d;
ll const N = 1e12+1;
ll memo[100009];
ll MEMO(int i){
    if(i == 0)
        return 1;

    ll &ret = memo[i];
    if(~ret)
        return ret;
    ret = 0;
    ret += MEMO(i-1);
    ret %= MOD;
    if((i-k) >= 0)
        ret += MEMO(i-(int)k);
    ret % MOD;    
    return ret % MOD;
}
vector<ll>ans(100009, 0);
int main() {
    KHALED_WALEED_ATTIA
    // cin >>t;
    // cout<<mp.size()<<endl;
    while(t--){
        cin >>n;
        vector<int>a(n);
        getV(a);
        sort(all(a));
        cin >>m;
        while(m--){
            int x;
            cin >>x;
            int ans = upper_bound(all(a),x) - a.begin();
            cout<<ans<<endl;
        }
    }
    
    return 0;
}
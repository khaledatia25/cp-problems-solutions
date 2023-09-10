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
ll x, minus, temp, ans, l, r, b, a;
ll const N = 1e12+1;
ll memo[12][101][101][2];
ll rec(ll i, ll sum, ll num,bool tr, vector<int>&a){
    if(i == a.size()){
        return (sum%k == 0 && num == 0);
    }
    ll &ret = memo[i][sum][num][tr];
    if(~ret)
        return ret;

    ll lmit = (tr == 0) ? a[i] : 9;
    ret = 0;
    for(int dg = 0; dg <= lmit; dg++){
        bool ok = (tr || dg < a[i]);
        ret += rec(i+1,(sum + dg)%k, ((num*10)%k+(dg%k))%k, ok, a);
    }    
    return ret;
}

int main() {
    KHALED_WALEED_ATTIA
    cin >>t;
     
    
    int cnt=1;
    // cout<<mp.size()<<endl;
    while(t--){
        cin >> a >>b >>k;
        vector<int>aa, bb;
        cout<<"Case "<<cnt++<<": ";
        a--;    
        while(a){
            aa.push_back(a%10);
            a /= 10;
        }
        while(b){
            bb.push_back(b%10);
            b /= 10;
        }
        reverse(all(aa));
        reverse(all(bb));
        if(k > 81){
            cout<<0<<endl;
        }else{
            setting(memo, -1);
            ll ans = rec(0,0,0,0,bb);
            setting(memo, -1);
            ans -= rec(0,0,0,0,aa);
            cout<<ans<<endl;
        }
    }
    
    return 0;
}
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
ll x,w, minus, temp,  l, r,d,k1,k2;
ll const N = 1e12+1;
vector<vector<ll>>memo1(155, vector<ll>(15005,0));
vector<vector<ll>>memo2(155, vector<ll>(15005,0));
ll mm = 100000000;
ll MEMO(int i, int num,vector<int> &a,int n,vector<vector<ll>> &memo){   
    if(i == n || num <= 0)
        return (num == 0);
    ll &ret = memo[i][num];
    if(~ret)
        return ret;
    ret = 0;
    ret += MEMO(i+1, num, a,n,memo);
    ret%=MOD;
    ret += MEMO(i+1,num-a[i], a,n,memo);
    ret %= MOD;

    return ret % MOD;   

}


int main() {
    KHALED_WALEED_ATTIA
    cin >>t;
    // cout<<mp.size()<<endl;
    while(t--){
        cin >>n >>m >>k >>w;
        vector<int> a(n), b(m);
        memo1 = vector<vector<ll>>(155, vector<ll>(15005,-1));
        memo2 = vector<vector<ll>>(155, vector<ll>(15005,-1));
        for(int i = 0; i < n; i++)
            cin >>a[i];
        for(int j = 0; j < m; j++)
            cin >>b[j];
        ll ans = 0, temp1,temp2;
        for(int i = 0; i <= w; i++){
            if(abs(i - (w-i)) <= k){
                temp1 = MEMO(0,i,a,n,memo1);
                temp2 = MEMO(0, w-i,b, m, memo2);
                ans += (temp1*temp2)%MOD;
                ans %= MOD;
            }
        }   
        cout<<ans<<endl;
    }
    
    return 0;
}
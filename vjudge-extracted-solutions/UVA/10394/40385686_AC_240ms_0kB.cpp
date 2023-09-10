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
#define fr0(a,b) for(int a=0;a<=b;a++)
#define fr1(a,b) for(int a=1;a<=b;a++)
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
ll const N = 2e7+1;
int p[150][150];
ll MM = 998244353;
string s;
int f(int n){
    if(n == 1)
        return 1;
    if(n&1)
        return 1+f(3*n+1);
    else
        return 1+f(n/2); 
}
bitset<20000003>notPrime;
vector<ll>primes;
void linear_sieve(){
    notPrime[0] = notPrime[1] = 1;
    for(ll i = 2; i < N; i++){
        if(!notPrime[i]){
            primes.push_back(i);
        }
        for(ll j = 0; j < primes.size() and i * primes[j] < N; j++){
            notPrime[primes[j]*i] = 1;
            if(i%primes[j] == 0)break;
        }
    }
}
int main() {
    KHALED_WALEED_ATTIA
    // cin>>t;
    linear_sieve();
    vector<pair<ll,ll>>ans;
    for(ll i : primes){
        if(!notPrime[i+2])
            ans.emplace_back(i, i+2);
    }
    
    while(cin >>n){
        
        cout<<"("<<ans[n-1].first<<", "<<ans[n-1].second<<")"<<endl;    
    }
    
    return 0;
}


/*
15 -> 5 * 3
20 -> 5 * 2 * 2

14 -> 7 * 2 
8 -> 2 * 2 * 2

15 -> 5 * 3 
18 -> 2 * 3 * 3

25 -> 5 * 5
50 -> 5 * 5 * 2

35 -> 5 * 7
14 -> 2 * 7

*/ 
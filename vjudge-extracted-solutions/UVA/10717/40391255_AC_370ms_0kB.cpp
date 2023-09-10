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
#define frs(a,s,b) for(int a=s;a<=b;a++)
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
ll const N = 1e7+1;
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
vector<ll>prevPrime(N);
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
    prevPrime[0]=prevPrime[1]=0;
    prevPrime[2]=2;
    for(ll i = 3; i<N;i++){
        if(notPrime[i])
            prevPrime[i]=prevPrime[i-1];
        else
            prevPrime[i]=i;    
    }

}
ll r;
vector<ll>b(3),p(3), g(3);
bool pred(ll num){
    ll cost = 0;
    for(int i = 0; i < 3; i++){
        if(num*g[i]>b[i]){
            cost += (num*g[i] - b[i]) * p[i];
        }
    }
    return cost <= r;
}
ll BS(){
    ll lo = 0, hi = 10e12+3, mid, ans;
    while(lo<=hi){
        mid = (lo + hi)/2;
        if(pred(mid)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid - 1;
        }
    }
    return ans;
}
int main() {
    KHALED_WALEED_ATTIA
    // cin>>t;
    while(t){
        cin >>n >>m;
        if(!n&&!m)return 0;
        vector<int>v(n), h(m);
        for(int i = 0; i < n; i++)
                cin >>v[i];
        frs(i,0,m-1)cin>>h[i];
        for(int height : h){
            int ans1=INT_MIN, ans2=INT_MAX;
            frs(i,0, n-1){
                frs(j,i+1,n-1){
                    frs(k,j+1,n-1){
                        frs(l,k+1,n-1){
                            vector<int>vv{v[i],v[j],v[k],v[l]};
                            int num = 1;
                            frs(o,0,3){
                                num = vv[o]/__gcd(num, vv[o])*num;
                            }
                            int mm = height/num;
                            if(height%num != 0){
                                ans1=max(ans1, mm*num);
                                ans2 = min(ans2, (mm+1)*num);
                            }else{
                                ans1=max(ans1, mm*num);
                                ans2 = min(ans2, mm*num);
                            }
                        }
                    }   
                }
            }
            cout<<ans1<<space<<ans2<<endl;
        }
        

    }
    
    return 0;
}



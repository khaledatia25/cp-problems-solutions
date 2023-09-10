#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
void fileInput();
const int N = 10000000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
const ll mod = 1000000007;

bool notPrime[N];
int prevPrime[N];
void sieve(){
    notPrime[0]=notPrime[1]=1;
    for(int i = 2; i*i < N; i++){
        if(!notPrime[i]){
            for(int j = i*i; j < N; j+= i){
                notPrime[j]=1;
            }
        }
    }
    prevPrime[0]=prevPrime[1] = 0;
    prevPrime[2] = 2;
    int previous = 3;
    for(int i = 3; i < N; i++){
        if(notPrime[i]){
            prevPrime[i] = previous;
        }else{
            prevPrime[i] = i;
            previous = i;
        }
    }
}

ll even_sum(ll n){
    ll a = n/2;
    return a*(a+1);
}
ll odd_sum(ll n){
    ll a = n/2 + (n%2);
    return a*a;
}
int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int n,m;
    cin >>n >>m;
    int v[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >>v[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll ones = 0, zeros = 0;
        for(int j = 0; j < m; j++){
            if(v[i][j] == 1)
                ones++;
            else
                zeros++;
        }
        ans += (1LL<<ones)-1LL;
        ans += (1LL<<zeros)-1LL;
    }
    for(int j = 0; j < m; j++){
        ll ones = 0, zeros = 0;
        for(int i = 0; i < n; i++){
            if(v[i][j] == 1)
                ones++;
            else
                zeros++;
        }
        ans += (1LL<<ones)-1LL;
        ans += (1LL<<zeros)-1LL;
    }
    cout<<ans - m*n<<endl;
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
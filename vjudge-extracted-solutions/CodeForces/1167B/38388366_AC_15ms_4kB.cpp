//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/



bool is_power_of2(ll n){
    return (n&&!(n&(n-1)));
}
bool is_prime(ll n){
    if(n==2)return 1;
    if(n==0||n==1)return 0;
    for(ll i = 2; i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
ll gcd(ll a, ll b){
    while (b){
        ll aa = a;
        a = b;
        b = aa%b;
    }
    return a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b) * b;
}
vector<pair<int,int>>vp;
int arr[4], num[6] = {4, 8, 15, 16 , 23, 42};
ll t=1, n,k,m,a,x, max_weight = 13;

int main() {
    init();
//    cin >>t;
//    cin >>n;
    while(t--){
        n = 4;
        int i = 1,j=2,k=0;
        while (n--){
            cout<<'?'<<space<<i++<<space<<j++<<endl;
            fflush(stdout);
            cin >>arr[k++];
        }
        do{
            bool ii=1;
          for(int i = 0; i <4; i++){
              if(num[i]*num[i+1]!=arr[i])ii=0;
          }
          if(ii)break;
        } while (next_permutation(num,num+6));
        cout<<"! ";
        for(int i : num)cout<<i<<space;

    }

    return 0;
}
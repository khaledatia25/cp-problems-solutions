/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define endl "\n"
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
const int N = 200005;

ll n,m,k;
int t=1;
int a[100005], b[100005], c[100005];
int dp[10005][105];

bool rec(int i,int rem){
    if(i == n)
        return rem == 0;
    int &ret = dp[i][rem];
    if(~ret)return ret;

    ret = rec(1+i, (rem%k + a[i]%k)%k) || rec(i+1, (rem%k - a[i]%k + k)%k);
    return ret;      
}

int main() {
    FIO;  
    cin >>t;
    // int cnt=1;
    while(t--){
        cin >>n >>k;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++)cin >>a[i];
        if(rec(0,0))
            cout<<"Divisible"<<endl;
        else
            cout<<"Not divisible"<<endl;    
    }
    return 0;
}
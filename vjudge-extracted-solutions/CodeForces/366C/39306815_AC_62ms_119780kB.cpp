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
// const int N = 200005;

ll n,m,k,x,y;
int t=1;

int dp[102][300002];
int a[1000], b[1000];
vector<int>dots;
string s;

int rec(int i, int sum){  
        if(i==n){
            if(sum == 0)
                return 0;
            return -1e9;
        }
        int &ret = dp[i][sum];
        if(~ret)return ret;
        ret = rec(i+1, sum);
        ret = max(rec(i+1,sum + (a[i]-k*b[i])) + a[i], ret);

        return ret;

}

int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    bool f = 0;
    while(t--){
        cin >>n >>k;
        for(int i = 0; i < n; i++)cin >>a[i];
        for(int i = 0; i < n; i++)cin >>b[i];

        memset(dp, -1, sizeof(dp));
        if(rec(0, 0)>0)
            cout<<rec(0,0)<<endl;    
        else 
            cout<<-1<<endl; 
    }
    return 0;
}
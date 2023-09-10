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

int dp[2002][2002];
int dp1[2002][2002];
int a[20000], b[1000];
vector<int>dots;
string s;

int LIS(int i, int prev){  
        if(i==n)
            return 0;

        int &ret = dp[i][prev];
        if(~ret)return ret;
        
        ret = max(ret, LIS(i+1, prev));
        if(a[i] > a[prev])
            ret = max(ret, 1+LIS(i+1, i));

        return ret;

}

int LDS(int i,int prev){
             if(i==n)
                return 0;

            int &ret = dp1[i][prev];
            if(~ret)return ret;
            
            ret = max(ret, LDS(i+1, prev));
            if(a[i] < a[prev])
                ret = max(ret, 1+LDS(i+1, i));

            return ret;
}


int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    bool f = 0;
    while(t--){
        cin >>n;
        for(int i = 0; i < n; i++)cin >>a[i];
        memset(dp, -1, sizeof(dp));
        memset(dp1, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(LIS(i, i)+LDS(i,i)+1,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
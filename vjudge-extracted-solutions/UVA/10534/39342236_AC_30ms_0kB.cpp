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
ll inf = 1e9+1;
ll n,m,k,x,y;
int t=1;

vector<int>LIS(vector<int>&a, int n){
    vector<int>dp, ans(n);
    for(int i = 0; i < n; i++){
            int j = lower_bound(dp.begin(), dp.end(), a[i])-dp.begin();
            if(j == dp.size())
                dp.push_back(a[i]);
            else    dp[j] = a[i];
            ans[i] = j+1;    
        }
    return ans;    
}



int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(cin >>n){
        vector<int>a(n);
        for(int &i : a)cin >>i;
        vector<int>f,b;
        f = LIS(a,n);
        reverse(a.begin(), a.end());
        b = LIS(a,n);
        reverse(b.begin(), b.end());
        int ans = -1;
        for(int i = 0; i < n; i++){
            ans = max(ans, 2*min(f[i],b[i]) - 1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
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
const int N = 100005;

int n,m,k;
string s1, s2;

int summ = 0;
string s;

vector<pair<int, int>> v;
int dp[1002][300];
int w[1002], p[1002];
bool taken[1002];
int max_w;

int rec(int i,int weight){
        if(i == n)
            return 0;
        if(dp[i][weight] != -1)return dp[i][weight];    
        if(w[i]+weight <= max_w)
            dp[i][weight] =  max(p[i]+rec(i+1, weight+w[i]), rec(i+1, weight));
        else    
            dp[i][weight] = rec(i+1, weight);
        return dp[i][weight];        
}   

void solves(int ttt){
    cin >>n;
    for(int i = 0; i < n; i++)cin >>p[i] >>w[i], taken[i] = 0;
    cin >>m;
    int ans = 0;
    while(m--){
        memset(dp, -1, sizeof(dp));
        cin >>max_w;
        ans += rec(0,0);
    }
    cout<<ans<<endl;
}   

int t=1;
int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    while(t--){
       solves(t);

    }
    return 0;
}
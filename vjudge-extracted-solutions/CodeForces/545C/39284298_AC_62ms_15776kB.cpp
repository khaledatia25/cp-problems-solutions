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

int n,m;
string s1, s2;

int summ = 0;
string s;

vector<pair<int, int>> v;
int dp[N][3];
int rec(int i,int last, int op){
    if(i == n)
        return 0;
    int x = v[i].first;
    int h = v[i].second;
    int &ans = dp[i][op];
    if(~ans)return ans;     
    ans = max(ans,rec(i+1,x,0));

    if(x-h>last){
        ans = max(rec(i+1,x,1)+1, ans);
    }
    if(i == n-1)ans=max(ans, rec(i+1, x+h,2)+1);
    else if(x+h<v[i+1].first)ans = max(ans, rec(i+1, x+h, 2)+1);
    return ans;    

    
}

void solves(int ttt){
    cin >>n;
    memset(dp, -1, sizeof(dp));
    int x, h;
    for(int i = 0; i < n; i++){
        cin >>x >>h;
        v.emplace_back(x, h);
    }
    cout<<rec(0,INT_MIN, 1)<<endl;
   
}   

int t=1;
int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(t--){
       solves(cnt++);

    }
    return 0;
}
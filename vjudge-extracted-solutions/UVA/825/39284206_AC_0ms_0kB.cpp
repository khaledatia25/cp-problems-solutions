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

ll n,m,k;
int t=1;

vector<vector<int>>dp;
vector<vector<bool>>notSafe;

int rec(int i, int j){
    if(i > n||j>m || notSafe[i][j]){
        return 0;
    }
    if(i == n && j == m)
        return 1;
    int &ret = dp[i][j];
    if(~ret)return ret;

    ret = rec(i+1, j)+ rec(i, j+1);
    return ret;
}

int main() {
    FIO;  
    cin >>t;
    // int cnt=1;
    bool f = 0;
    while(t--){
        cin >>n >>m;
        cin.ignore();
        dp = vector<vector<int>>(n+1, vector<int>(m+1,-1));
        notSafe = vector<vector<bool>>(n+1, vector<bool>(m+1, 0));
        for(int i = 0; i < n;i++){
            string s; getline(cin,s);
            stringstream ss(s);
            int r, c;
            ss >>r;
            while(ss>> c){
                notSafe[r][c]=1;
            }
        } 
        
        if(f)cout<<endl;
        f=1;
        cout<<rec(1,1)<<endl;
         
    }
    return 0;
}
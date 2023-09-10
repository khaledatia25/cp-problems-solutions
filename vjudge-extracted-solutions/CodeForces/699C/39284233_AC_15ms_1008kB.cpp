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
char grid[1008][1008];
int arr[1002];
int dp[105][4];
int rec(int i,int prev_task){
    if(i == n)
        return 0;
    if(prev_task != -1 and dp[i][prev_task] != -1)return dp[i][prev_task];
    if(arr[i] == 0){
        dp[i][prev_task] = 1+rec(i+1, 0);
    }else if(arr[i] == 1){
        if(prev_task == 1)
            dp[i][prev_task] = 1+rec(i+1,0);
        else
            dp[i][prev_task] = rec(i+1, 1);    
    }else if(arr[i] == 2){
        if(prev_task == 2)
            dp[i][prev_task] = 1+rec(i+1, 0);
        else
            dp[i][prev_task] = rec(i+1, 2);    
    }else{
        if(prev_task == 1)
            dp[i][prev_task] = rec(i+1, 2);
        else if(prev_task == 2)
            dp[i][prev_task] = rec(i+1, 1);
        else
            dp[i][prev_task] = min(rec(i+1, 2), rec(i+1, 1));        

    }    
    return dp[i][prev_task];
    
}

void solves(int ttt){
    cin >>n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)cin >>arr[i];
    cout<<rec(0,-1)<<endl;                
   
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
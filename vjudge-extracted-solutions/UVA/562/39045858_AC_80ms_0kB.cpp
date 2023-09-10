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
int dp[102][50002];
int arr[100005];
int rec(int i,int x, int y){
        if(i == n)
            return abs(y-x);
        int diff = abs(x-y);
        int &ret = dp[i][diff];
        if(ret != -1)return ret;
        ret =  min(rec(i+1, x, y+arr[i]), rec(i+1, x+arr[i], y));
        return ret;
}

void solves(int ttt){
    cin >>n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    }
    cout<<rec(0, 0, 0)<<endl;    
   
}   

int t=1;
int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    while(t--){
       solves(cnt++);

    }
    return 0;
}
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
int dp[10005][100];
int arr[100005];
bool rec(int i,int mod){
        if(i == n)
            return mod == 0;
        mod = mod%k;    
        int &ret = dp[i][mod];
        if(ret != -1)return ret;    
        ret =  rec(i+1, (mod+arr[i])%k) || rec(i+1, (mod-arr[i])%k);    
        return ret;
}

void solves(int ttt){
    cin >>n >>k;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    }
    if(rec(1,arr[0]%k))
        cout<<"Divisible"<<endl;
    else    
        cout<<"Not divisible"<<endl;    
   
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
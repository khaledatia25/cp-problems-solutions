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
// int arr[100005];
int rec(int i,int x, int y){
        
}

void solves(int ttt){
    n = ttt;
   int arr[n][n];
   int mx = INT_MIN;
   for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >>arr[i][j], mx = max(mx, arr[i][j]);
   int temp[n];
    int ans = INT_MIN,sum;
   for(int s = 0; s < n; s++){
        memset(temp, 0, sizeof(temp));
        for(int e = s; e < n; e++){
            sum = 0;
            for(int i = 0; i < n; i++){
                temp[i] += arr[i][e];
                sum += temp[i];
                if(sum<0)sum = 0;
                ans = max(ans, sum);
            }
            
        }
   }     
   if(ans <= 0)
        cout<<mx<<endl;
    else        
        cout<<ans<<endl;
}   

int t=1;
int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(cin>>t){
       solves(t);

    }
    return 0;
}
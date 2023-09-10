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

vector<vector<ll>>memo(1004, vector<ll>(1004, -1));
string s;

ll rec(int i, int j){
    if(i >= j)return 0;
    
    ll &ret = memo[i][j];
    if(~ret)return ret;

    
    if(s[i] == s[j])
        ret = rec(i+1, j-1);
    else 
        ret = 1+min({rec(i+1, j-1), rec(i,j-1), rec(i+1, j)});
    return ret;    

}

int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    bool f = 0;
    while(t--){
        cin >>s;
        memo = vector<vector<ll>>(1004, vector<ll>(1004, -1));
        cout<<"Case "<<cnt++<<": "<<rec(0, s.size()-1)<<endl;
         
    }
    return 0;
}
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

vector<vector<ll>>memo(100, vector<ll>(100, -1));
string s;

ll rec(int i, int j){
    if(i == j)return 1;
    if(i+1 == j)return 2+(s[i]==s[j]);
    
    ll &ret = memo[i][j];
    if(~ret)return ret;

    ret = 0;
    if(s[i] == s[j])
        ret += rec(i+1, j-1) + 1;

    ret += rec(i+1, j);
    ret += rec(i, j-1);
    ret -= rec(i+1, j-1);

    return ret;    

}

int main() {
    FIO;  
    cin >>t;
    // int cnt=1;
    bool f = 0;
    while(t--){
        cin >>s;
        memo = vector<vector<ll>>(100, vector<ll>(100, -1));
        cout<<rec(0, s.size()-1)<<endl;
         
    }
    return 0;
}
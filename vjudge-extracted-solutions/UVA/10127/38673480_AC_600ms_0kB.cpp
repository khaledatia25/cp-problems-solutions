/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/


bool divisible(string s,int MOD){
    int ret = 0;
    for(int i = 0; i < s.size(); i++){
        ret = ret*10 + (s[i] - '0');
        ret = (ret%MOD);
    }
    return (ret%MOD) == 0;
}
void solve(int n){
    string ans = "1";
    while(1){
        if(divisible(ans, n))break;
        ans.push_back('1');
    }
    cout<<ans.size()<<endl;
}
int main() {
    FIO;
    ll t = 1,n;
    while(cin >>n)
        solve(n);    

    return 0;
}



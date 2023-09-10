/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 
using namespace std;


/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
int bigMOD(string num, int mod){
    int ret = 0;
    for(int i = 0; i < num.size(); i++){
        ret = (ret*10+(num[i] - '0'));
        ret = (ret%mod);
    }
    return ret%mod;
}

void solve(){
    int n;cin >>n;
    string s = string(n,'0');
    s[0] = '1';
    if(n < 3){
        cout<<-1;
        return;
    }
    int add = bigMOD(s,210);
    string s2 = to_string(210-add);
    for(int i = 0; i <s2.size();i++){
        s[s.size() - 1 - i] += (s2[s2.size() - 1 - i]-'0');
    }
    cout<<s<<endl;
}
int main() {
    FIO;
    int t = 1;
    while(t--)
        solve();
    return 0;
}



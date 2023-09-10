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

int step, mod;
void solve(){
    vector<int>randoms(mod, 0);
    for(int i = 1; i < mod; i++){
        randoms[i] = (randoms[i-1] + step)%mod;
    }
    sort(randoms.begin(), randoms.end());
    for(int i = 0; i < mod; i++){
        if(randoms[i] != i){
            cout<<fixed<<setw(10)<<step<<setw(10)<<mod<<"    Bad Choice\n"<<endl;
            return;
        }
    }
    cout<<fixed<<setw(10)<<step<<setw(10)<<mod<<"    Good Choice\n"<<endl;

}
int main() {
    FIO;
    
    while(cin >>step >>mod)
        solve();
    return 0;
}



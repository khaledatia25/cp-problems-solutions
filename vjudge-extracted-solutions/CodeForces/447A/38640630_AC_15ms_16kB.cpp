//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

int t =1,n,m=1, p;
map<int , bool>mp;
void solve() {
    cin >>p >>n;
    int cnt = 1;
    while(n--){
        cin >>m;
        if(!mp[m%p])
            mp[m%p] = 1;
        else{
            cout<<cnt<<endl;
            return;
        }
        cnt++;
    }
    cout<<-1<<endl;
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
//    cin >>t;
    int cnt = 0;
    while (t--){
        solve();
    }

//    fclose(stdout);
    return 0;
}



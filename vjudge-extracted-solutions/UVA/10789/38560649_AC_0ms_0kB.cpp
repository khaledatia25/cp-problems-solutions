//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define MOD 1000000007
#define dbl double
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

ll t =1,n,m=1, arr[25];

bool is_prime(int n){
    if(n == 2)
        return 1;
    if(n == 1 || n%2 == 0)
        return 0;
    for(int i = 3; i*i <= n; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

void solve() {
    string s; cin >>s;
    int freq[256] = {0};
    for(int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }
    bool empty = true;
    for(int i = 0; i < 256; i++){
        if(is_prime(freq[i]))
            cout<<(char)i, empty=0;
    }
    if(empty)
        cout<<"empty";
    
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
    cin >>t;
    int cnt = 1;
    while (t--){
        cout<<"Case "<<cnt++<<": ";
        solve();
        cout<<endl;
    }

//    fclose(stdout);
    return 0;
}



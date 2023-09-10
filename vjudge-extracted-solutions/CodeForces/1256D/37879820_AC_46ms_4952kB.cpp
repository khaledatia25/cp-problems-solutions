// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

int main() {
    init();
    int t = 1;
    cin >>t;
    while(t--){
        ll n  , k;
        cin >>n >>k;
        string s, res;
        cin >>s;
        int c = 0;
        bool done = false;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                c++;
            }else{
                if(c <= k){
                    res += '0';
                    k -= c;
                }else{
                    res += string(c - k, '1');
                    res += '0';
                    res += string(k, '1');
                    res += s.substr(i + 1);
                    cout<<res<<endl;
                    done = true;
                    break;
                }
            }
        }
        if(!done){
            cout<<res<<string(c,'1')<<endl;
        }
    }
    return 0;
}








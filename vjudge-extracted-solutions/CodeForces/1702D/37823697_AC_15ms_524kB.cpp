// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;

int main() {
    init();
    int t;cin >>t;
    while(t--){
        string s;
        cin >>s;
        int p; cin >>p;
        string w = s;
        sort(w.rbegin(), w.rend());
        int totalCost = 0;
        for(char i : w){
            totalCost += (int)(i - 'a' + 1);
        }
        map<char, int> mp;
        for(char i : w){
            if(totalCost > p){
                mp[i]++;
                totalCost -= (i - 'a' + 1);
            }else{
                break;
            }
        }
        for(char i : s){
            if(mp[i] > 0){
                mp[i]--;
            }else{
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}








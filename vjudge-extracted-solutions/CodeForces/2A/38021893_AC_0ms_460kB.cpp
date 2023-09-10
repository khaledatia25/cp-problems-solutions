// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0);cin.sync_with_stdio(0);
using namespace std;
int n, maxi=INT_MIN, score[10001]; string winner, name[10001];
map<string, int> mp, t;
 
/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
int main() {
    fast;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>name[i]>>score[i];
        mp[name[i]] +=score[i];
    }
    for(auto i : mp){
        maxi= max(maxi, i.second);
    }
//    cout<<maxi<<endl;
    for(int i = 0; i < n; i++){
        t[name[i]] += score[i];
        if(t[name[i]] >= maxi && mp[name[i]]==maxi){
            cout<<name[i];
            return 0;
        }
    }
//    cout<<winner;
    return 0;
}
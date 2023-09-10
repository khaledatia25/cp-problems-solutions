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
ll pred(map<ll, ll>mp, ll k){
    ll ans = 0;
    for(auto i : mp){
        if(i.second >= k){
            ans += (i.second - k);
        } else {
            ans += i.second;
        }
    }
    return ans;
}
int main() {
    init();
    int t = 1;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        map<ll,ll>mp, me;
        ll temp;
        for(int i = 0; i < n; i++)cin >>temp, mp[temp]++, me[mp[temp]]++; // Calculating frequency of numbers and how many times this frequency happened, so we can indicate the answer in linear time
        ll ans = INT_MAX;
        for(auto i : mp){
            ans = min(ans, n - i.second * me[i.second]);
            /*
             * i.second * me[i.second] give us number of elements that will be kept to make our array beautiful
             * by subtracting, we get number of elements removed
             * by iterating through all frequencies taking minimum number of removed elements we get the correct answer.
             * Good Luck!
             * */
        }
        cout<<ans<<endl;

    }
    return 0;
}








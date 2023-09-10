//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

ll t=1, n,x, max_weight = 13,m;
vector<vector<ll>>v;
ll sum = 0;
int rotated[10000009] = {0};
//return number of digits
int numberLen(ll n){
    string s = to_string(n);
    return s.size();
}
//return a number after doing operation two
bool pred(ll n){
    string s = to_string(n);
    return s[s.size()-1] == '3';
}
vector<int>ans;
void p(ll x, int cnt=0){
    if(cnt > 10005)
        return;
    if(x%3!=0&&pred(x))
        ans.push_back(x);
    p(x+1,cnt+1);
}

int main() {
    init();
    cin >>t;
//    sort(ans.begin(),ans.end());
    for(int i = 1;i<100000;i++){
        if(i%3!=0&&i%10!=3)
            ans.push_back(i);
    }
//    cout<<ans.size();
    while(t--){
        cin >>n;
        cout<<ans[n-1]<<endl;

    }

    return 0;
}



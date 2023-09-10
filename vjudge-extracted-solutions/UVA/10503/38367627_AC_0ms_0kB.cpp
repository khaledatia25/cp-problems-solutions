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

int t=1, n,k,m,a,x, max_weight = 13;

bool is_power_of2(ll n){
    return (n&&!(n&(n-1)));
}
bool is_prime(ll n){
    if(n==2)return 1;
    if(n==0||n==1)return 0;
    for(ll i = 2; i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
vector<pair<int,int>>vp;
int taken[1000] = {0};
bool p(int current_r, int last_l, int cnt = 0){
    if(cnt == n)
        return (current_r==last_l);
    if(cnt > n)
        return 0;
    bool found = 0;
//    cout<<current_r<<space<<cnt<<endl;
    for(int i =0; i<m;i++){
        if(taken[i])continue;
        taken[i]=1;
        if(current_r == vp[i].first)
            found = p(vp[i].second,last_l,cnt+1);
        if(found)break;
        if(current_r == vp[i].second)
            found = p(vp[i].first,last_l,cnt+1);
        if(found)break;
        taken[i] = 0;
    }
    return found;
}
int main() {
    init();
//    cin >>t;
//    cin >>n;
    while(1){
        cin >>n;
//        cout<<m;
        if(n==0)break;
        cin >>m;
        pair<int,int>l,r;
        cin >>l.first >>l.second;
        cin >>r.first >>r.second;
        for(int i = 0; i < m; i++){
            int li,ri;
            cin >>li >>ri;
            vp.emplace_back(li,ri);
            taken[i]=0;
        }
        if(p(l.second,r.first))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        vp.clear();


    }

    return 0;
}



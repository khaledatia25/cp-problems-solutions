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
ll gcd(ll a, ll b){
    while (b){
        ll aa = a;
        a = b;
        b = aa%b;
    }
    return a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b) * b;
}
vector<pair<int,int>>vp;
int arr[4], num[6] = {4, 8, 15, 16 , 23, 42};
ll t=1, k,m,a,x, max_weight = 13;

int p(string s,char c){
    int n = s.size();
    if(s.size() < 2){
        return (s[0] != c);
    }
    string s1 = s.substr(0,n/2), s2 = s.substr(n/2,n/2);
    int cnt1 = n/2-count(s1.begin(), s1.end(), c);
    int cnt2 = n/2- count(s2.begin(),s2.end(),c);
    return min(cnt1+p(s2,c+1),cnt2+p(s1,c+1));
}

int main() {
    init();
    cin >>t;
//    cin >>n;
    while(t--){
        string s;
        cin >>m;
        cin >>s;
        cout<<p(s,'a')<<endl;


    }

    return 0;
}



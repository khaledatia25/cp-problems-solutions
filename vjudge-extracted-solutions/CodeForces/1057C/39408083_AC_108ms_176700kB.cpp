/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define setting(x, i) memset(x, i, sizeof(x))
#define all(v) v.begin(), v.end()
#define getV(v) for(int& i : v)cin>>i
#define endl "\n"
using namespace std;

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;
ll inf = 1e9+1;
ll n,m,k,y;
int t=1;



vector<int>v;
vector<int>colors;
ll memo[4][53][53][2009];
ll sol(int prev_color, int i, int prev_r, int cur){
    if(cur>=k)
        return 0;
    if(i < 0 || i >= n)
        return 1e12;
    ll& ret = memo[prev_color][i][prev_r][cur];
    if(~ret)return ret;

    ret = 1e12;
    
    for(int j = 0; j < n; j++){
        if(colors[j] != prev_color&&prev_r < v[j]){
            int temp = v[j];
            v[j] = 0;
            ret = min(ret, abs(i-j)+sol(colors[j], j, temp, cur+temp));
            v[j] = temp;
        }
    }
        

    return ret;
}   

int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    
    while(t--){
        int ss;
        cin >>n >>ss >>k;
        v = vector<int>(n);
        colors = vector<int>(n);
        getV(v);
        setting(memo, -1);
        string s;
        cin >>s;
        for(int i = 0; i < n; i++){
            if(s[i] == 'R')colors[i]=1;
            if(s[i] == 'G')colors[i]=2;
            if(s[i] == 'B')colors[i]=3;
            
        }
        ll ans = sol(0,ss-1,0,0);
        cout<<(ans < 1e12 ? ans:-1 )<<endl;
    }
    return 0;
}
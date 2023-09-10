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
#define mkV(v, type, l, i) v=vector<type>(l, i)
#define getV(v) for(auto& i : v)cin>>i
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
ll sol(int i, int j, int sum){
    if(sum > k)
        return 40;

    if(i>=j)
        return sum;
    if(v[i] == v[j])
        return sol(i+1,j-1,sum);
    else return min(sol(i+1,j,sum+1), sol(i,j-1, sum+1));
}   

int main() {
    FIO;  
    cin >>t;
    int cnt=1;
    while(t--){
        cin >>n >>k;
        mkV(v,int,n,0);
        getV(v);
        int ans = sol(0,n-1,0);
        if(ans == 0)
            cout<<"Case "<<cnt++<<": Too easy"<<endl;
        else if(ans > k)
            cout<<"Case "<<cnt++<<": Too difficult"<<endl;
        else
            cout<<"Case "<<cnt++<<": "<<ans<<endl;

    }
    return 0;
}
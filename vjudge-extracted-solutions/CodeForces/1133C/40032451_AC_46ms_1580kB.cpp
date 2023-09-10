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
#define allr(v) v.rbegin(), v.rend()
#define mkV(v, type, l, i) v=vector<type>(l, i)
#define prefix(a, n) for(int i = 1; i < n; i++)a[i]+=a[i-1]
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
const int OO = 0x3f3f3f3f;
const int SZ = 1e5+5;
pair<int, int> arr[SZ];


int main() {
    FIO;  
    // cin >>t;
    int cnt=1;
    while(t--){
      cin >>n;
      vector<int>v(n);
      getV(v);
      sort(all(v));
      int p1 = 0, p2 = 0;
      int ans = 0;
      while(p2<n){
        int diff = v[p2]-v[p1];
        if(diff <= 5){
            ans = max(ans, p2-p1+1);
            p2++;
            continue;
        }
        p1++;
      }
      cout<<ans<<endl;
    }   
    return 0;
}
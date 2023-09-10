// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
int main() {
    init();
    int t = 1, n;
//    cin >>t;
    while (t--) {
          ll r, g, b;
          cin >>r >>g >>b;
          ll sum = r+g+b;
          if(r > g)swap(r, g);
          if(r > b)swap(r, b);
          if(g > b)swap(g,b);
          ll ans = min<ll>(sum/3, (r+g));
          cout<<ans;
    }
    return 0;
}








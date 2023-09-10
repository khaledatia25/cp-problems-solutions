#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
        
int main() {
    KHALED_WALEED_ATTIA
    int t = 1;
    cin >>t;
    while(t--){
        int n;
        vector<int>v(n);
        for(int &i : v)cin >>i;
        int gcd = v[0], ans = 0;
        for(int i = 1; i < n; i++){
            gcd = __gcd(v[i], v[i-1]);
            if(gcd == 1){
                ans = i+1;
            }
        }   
        if(ans)
            cout<<ans<<endl;
            else 
                cout<<-1<<endl;
                    if(t)
                    cout<<endl;
    }
    return 0;
}
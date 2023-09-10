#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
void fileInput();
const int N = 1000000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
const int mod = 1000000000;

int32_t main() {
    KHALED_WALEED_ATTIA
//    fileInput();
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        vector<int>arr(n);
        map<int, ll>freq;
        for(int &i : arr)
            cin >>i, freq[i]++;
        ll ans = 0;
        for(int i : arr){
                ans += freq[i] * (freq[i]-1LL);
                freq[i] = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
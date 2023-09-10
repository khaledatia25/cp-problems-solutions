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
    int t;
    cin >>t;
    while(t--){
        int n; cin >>n;
        int indeces[500009] = {0};
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >>arr[i], indeces[arr[i]] = i+1;

        int ans = 0;
        for(int i = 3; i < 2*n; i++){
            for(ll j = 1; j*j <= i; j++){
                if(i%j == 0 && i/j != j){
                    if(indeces[i/j]&&indeces[j]){
                        if(indeces[i/j] + indeces[j] == i){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;

int main() {
    KHALED_WALEED_ATTIA
    int n;
    while (cin >> n, n){
        int arr[n+1];
        for(int i = 0; i < n; i++)
            cin >>arr[i];
        int dp[n];
        memset(dp, 1, sizeof dp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int ans = 0, pos = 0;
        for(int i = n-1; i >= 0; --i){
            if(dp[i] > ans){
                ans = dp[i];
                pos = i;
            }
        }
        vector<int>seq;
        for(int i = pos; i>=0; i--){
            if(dp[i] == ans){
                seq.push_back(arr[i]);
                ans--;
            }
        }
        reverse(seq.begin(), seq.end());
        cout<<seq.size()<<space;
        for(int i : seq)cout<<i<<space;
        cout<<endl;
    }
    

    return 0;
}
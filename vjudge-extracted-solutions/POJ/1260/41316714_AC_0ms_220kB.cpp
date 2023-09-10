#include <iostream>
#include <stdio.h>
#include <string.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;

int main() {
    KHALED_WALEED_ATTIA
    int t;
    cin >>t;
    while(t--){
        int c;
        cin >>c;
        int a[101], p[101];
        for(int i =0; i < c; i++)
            cin >>a[i] >>p[i];

       int dp[109];
       dp[c] = 0;
       for(int i = c-1; i >= 0; i--){
            int sum = 0;
            dp[i] = INT_MAX;
            for(int j = i; j < c; j++){
                sum += a[j];
                dp[i] = min(dp[i],(sum + 10)*p[j] + dp[j+1]);
            }
       }
        cout<<dp[0]<<endl;
    }
    return 0;
}
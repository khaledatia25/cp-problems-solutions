#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 5000+9;

int main() {
    KHALED_WALEED_ATTIA
    int n, w;
    cin >>n >>w;
    ll weight[n], value[n];
    ll dp[n+1][w+1];
    /*
        f(index, reminder) -> f(index + 1, reminder)
                           -> value[index] + f(index + 1, reminder - weight[i])  condition weight[index] <= reminder
        f(index, reminder) = 0   index == n
    */
    for(int i = 0; i < n; i++){
        cin >> weight[i] >>value[i];
    }
    for(int index = n; index >= 0; index--){
        for(int reminder = 0; reminder <= w; reminder++){
            if(index == n){
                dp[index][reminder] = 0;
                continue;
            }
            ll ch1 = dp[index + 1][reminder]; // leaving element
            ll ch2 = 0;
            if(reminder >= weight[index])
                ch2 =  value[index] + dp[index + 1][reminder - weight[index]];
            dp[index][reminder] = max(ch1, ch2);
        }
    }
    cout<< dp[0][w]<<endl;
    return 0;
}
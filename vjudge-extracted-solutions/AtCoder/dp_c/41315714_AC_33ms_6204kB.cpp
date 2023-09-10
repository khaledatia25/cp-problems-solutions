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
    cin >>n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++)
        cin >>a[i] >>b[i] >>c[i];
    /*
        F(day, previous_activity) -> a[day] + F(day + 1, 1)  | previous_activity != 1
                                  -> b[day] + F(day + 1, 2)  | previous_activity != 2
                                  -> c[day] + F(day + 1, 3)  | previous_activity != 3
                                  -> 0              | day = n
    */
   int dp[n+1][4];

    for(int day = n; day >= 0; --day){
        for(int previous_activity = 3; previous_activity >= 0; --previous_activity){
            if(day == n){
                dp[day][previous_activity] = 0;
            }else{
                int ch1 = 0, ch2 = 0, ch3 = 0;
                if(previous_activity != 1)
                    ch1 = a[day] + dp[day + 1][1];
                if(previous_activity != 2)
                    ch2 = b[day] + dp[day + 1][2];
                if(previous_activity != 3)
                    ch3 = c[day] + dp[day + 1][3];
                dp[day][previous_activity] = max({ch1, ch2, ch3});    
                
            }
        }
    }
    cout<< dp[0][0] <<endl;

    return 0;
}
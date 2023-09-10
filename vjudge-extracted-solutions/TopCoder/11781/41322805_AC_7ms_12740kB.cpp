#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1},
        dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const ll mod = 1000000007;
vector<int>w;
class CasketOfStar {
public:
    CasketOfStar(){
        KHALED_WALEED_ATTIA
    }
    int maxEnergy(vector<int>v){
        int dp[v.size()][v.size()];
        for(int i = v.size()-1; i >= 0; i--){
            for(int j = 0; j < v.size(); j++){
                dp[i][j] = 0;
                for(int k = i+1; k < j; k++){
                    dp[i][j] = max(dp[i][j], v[i] * v[j] + dp[k][j] + dp[i][k]);
                }
            }
        }
        return dp[0][v.size() - 1];
    }
};
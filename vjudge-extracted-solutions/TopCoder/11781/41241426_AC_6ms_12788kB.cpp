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
const int N = 100+9;
int memo[N][N], p[N], a[N];
int n;
vector<int>w;
int naruto(int i, int j){
    if(j - i +1 <= 2)
        return 0;
    if(j - i + 1 == 3)
        return w[j]*w[i];
    int &ret = memo[i][j];
    if(~ret)
        return ret;

    ret = 0;
    for(int k = i+1; k < j; k++){
        ret = max(ret, w[i]*w[j] + naruto(i, k) + naruto(k, j));
    }
    return ret;
}
class CasketOfStar {
public:
    CasketOfStar(){
        KHALED_WALEED_ATTIA
        memset(memo, -1, sizeof memo);
    }
    int maxEnergy(vector<int>v){
        w = v;

        return naruto(0, w.size()-1);
    }
};
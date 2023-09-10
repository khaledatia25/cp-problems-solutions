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

class MergersDivTwo{
    int n;
    double memo[55];
    bool vis[55];
    int k;
    vector<int>pre;
public:
    double rec(int l){
        cout<<l;
        double &ret = memo[l];
        if(vis[l])
            return ret;
        vis[l] = 1;
        ret = 1.0 * (pre[n] - pre[l-1]) / (n-l+1);
        for(int i = l+k-1; i<=n-k+1;i++){
            ret = max(ret, (pre[i-1] - pre[l - 1] + rec(i)) / (i-l+1) );
        }
        return ret;
    }
    double findMaximum(vector<int> rev, int k){
        n = rev.size();
        this->k = k;
        memset(vis,0, sizeof vis);
        memset(memo,-1, sizeof memo);
        sort(rev.rbegin(), rev.rend());
        pre.resize(n+1);
        pre[0]=0;
        for(int i = 1; i <= n;++i)
            pre[i] = pre[i-1] + rev[i-1];
        return rec(1);
    }
};
// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
int minI(vector<int> v, int n){
    int minn = INT_MAX, idx;
    for(int i = 0; i < n; i++){
        if(v[i] < minn){
            idx = i;
            minn = v[i];
        }
    }
    return idx;
}
int maxI(vector<int> v, int n){
    int maxx = INT_MIN, idx;
    for(int i = 0; i < n; i++){
        if(v[i] > maxx){
            idx = i;
            maxx = v[i];
        }
    }
    return idx;
}
int main() {
    init();
    int n, k;
    cin >>n >>k;
    vector<int>v(n);
    for(int i = 0; i <n; i++)cin >>v[i];
    vector<pair<int, int>>ans;
    while (k--){
        int mi = minI(v, n);
        int ma = maxI(v, n);
        if(mi == ma)
            break;
        v[mi]++;
        v[ma]--;
        ans.emplace_back(make_pair(ma, mi));

    }
    sort(v.begin(), v.end());
    cout<<v[n - 1] - v[0]<<space<<ans.size()<<endl;
    for(auto i : ans)
        cout<<i.first+1<<space<<i.second+1<<endl;

    return 0;
}








#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0);
#define fr(l,n, h) for( int h = l; i < n; i++)
using namespace std;
void init(){fast;}
using ll =  long long;
ll  m, n,  t, sum = 0,   xi, yi, a, b;
 
int main() {
    init();
    cin >>n;
    vector<int>v(n);
    for(int i = 0; i < n; i++)cin >>v[i];
    vector<int>pre(n + 1, 0);
    for (int i = 1; i <= n; ++i)pre[i] = pre[i - 1] + v[i - 1];
    cin >>m;
    while (m--){
        cin >>xi;
        int ans = (int)(lower_bound(pre.begin(), pre.end(), xi) - pre.begin()) - 1;
        cout<<ans+1<<endl;
    }
    return 0;
}
 
 
 
 
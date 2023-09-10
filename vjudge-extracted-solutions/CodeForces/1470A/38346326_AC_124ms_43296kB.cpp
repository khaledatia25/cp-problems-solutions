//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

ll t=1, n,x, max_weight = 13,m;
vector<vector<ll>>v;
ll sum = 0;
int a[10000009] = {0};

bool p(int idx,ll sum){
    if(idx == n)
        return (sum==m);
    return p(idx+1, sum+a[idx])|| p(idx+1, sum-a[idx]);
}
vector<int> friends;
int main() {
    init();
    cin >>t;
    while(t--){
        cin >>n >>m;
        int num;
        for(int i = 0; i < n; i++)cin >>num, friends.push_back(num);
        sort(friends.rbegin(),friends.rend());
        for(int i = 0; i < m; i++)cin >>a[i];
        int available = 0;
        sum = 0;
        for(int i = 0; i < n; i++){
            if(available <= friends[i]-1){
                available++;
                sum += a[i];
            }else{
                sum+=a[friends[i]-1];
            }
        }
        cout<<sum<<endl;
        friends.clear();

    }

    return 0;
}



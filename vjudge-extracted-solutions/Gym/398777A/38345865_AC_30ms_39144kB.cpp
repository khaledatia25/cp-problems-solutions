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

int main() {
    init();
//    cin >>t;
    while(t--){
        cin >>n >>m;
        for(int i = 0; i < n; i++)cin >>a[i];
        if(p(1,a[0]))
            cout<<"YES";
        else
            cout<<"NO";


    }

    return 0;
}



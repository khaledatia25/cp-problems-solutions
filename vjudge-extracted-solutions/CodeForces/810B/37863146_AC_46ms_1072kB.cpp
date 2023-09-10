// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

int main() {
    init();
    int n, f, k, l, c;
    ll sum=0;
    cin >>n >>f;
    vector<int>v;
    for(int i = 0; i < n; i++){
        cin >>k >>l;
        c = min(k, l);
        sum += c;
        v.push_back(min(2*k, l) - c);
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < f; i++)
        sum += v[i];
    cout<<sum;
    return 0;
}








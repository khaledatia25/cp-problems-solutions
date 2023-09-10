//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
#define mx_str "99999999999999999999999999"
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

ll t=5, n,x, max_weight = 13,m;
int a[100005];
vector<vector<int>>v(1008);
int cnt = 0;

pair<int, vector<int>> p(int idx,vector<int>&nums, ll sum=0){
    if(sum > m)
        return {INT_MIN, nums};
    if(idx >= n)
        return {sum, nums};
    nums.push_back(a[idx]);
    auto a1 = p(idx+1, nums, sum+(ll)a[idx]);
    nums.pop_back();
    auto a2 = p(idx+1, nums, sum);
    if(a1.first>a2.first)
        return a1;
    else
        return  a2;

}

int main() {
    init();
//    cin >>t;
    while(cin >>m){
        cin >>n;
        for(int i = 0; i < n; i++)cin>>a[i];
        vector<int>nums;
        auto a = p(0, nums,0);
        ll sum = 0;
        for(int i : a.second)cout<<i<<space,sum+=(ll)i;
        cout<<"sum:"<<sum;
        cout<<endl;

    }

    return 0;
}




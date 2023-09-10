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

ll t=1, n,x, max_weight = 13,m;
int a[100005];
vector<vector<int>>v(1008);

int cnt = 0;
void p(int idx, int sum,vector<int>&nums , vector<int>& res, int t){
//    cout<<idx<<endl;
    if(sum == t) {
        cnt++;
        for(auto it = res.begin(); it != res.end(); it++){
            cout<<*it;
            if(it != res.end()-1)cout<<"+";
        }
        cout<<endl;
        return;
    }
    if(idx >= nums.size() || sum > t)return;
    for(int i = idx; i <nums.size(); i++){
        if(i  > idx && nums[i] == nums[i-1])continue;
            res.push_back(nums[i]);
            p(i+1, sum+nums[i],nums,res,t);
            res.pop_back();

    }
}

int main() {
    init();
//    cin >>t;
    while(t){
        v.clear();
        cin >>m >>n;
        vector<int>temp;
        vector<int>nums;
        if(n == 0 || m==0)break;
        for(int i = 0; i < n; i++){
            int h;cin>>h;
            nums.push_back(h);
        }
        cnt=0;
        cout<<"Sums of "<<m<<":"<<endl;
        p(0,0,nums, temp, m);
        if(!cnt)cout<<"NONE\n";

    }

    return 0;
}

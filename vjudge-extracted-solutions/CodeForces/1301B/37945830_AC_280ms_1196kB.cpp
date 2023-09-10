// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
int pred(vector<int>v,int k){
    int mx = INT_MIN;
    for(int i = 0; i < v.size(); i++)
        if(v[i] < 0)v[i] = k;
    for(int i = 1; i < v.size(); i++)
        mx = max(abs(v[i - 1] - v[i]), mx);
    return mx;
}
pair<int , int> TS(vector<int>v){
    int lo = 0, hi = 1000000000, mid1, mid2, ans1, ans2, ans, k;
    while (lo <= hi){
        mid1 = lo + (hi - lo) / 3;
        mid2 = hi - (hi - lo) / 3;
        ans1 = pred(v, mid1);
        ans2 = pred(v, mid2);
        if(ans1 >= ans2){
            lo = mid1 + 1;
            ans = ans1;
            k = mid1;
        }else{
            hi = mid2 - 1;
        }
    }
    return {ans, k};
}
int main() {
    init();
    int t = 1, n;
    cin >>t;
    while (t--) {
          cin >>n;
          vector<int>v(n);
          for(int &i : v)cin>>i;
          pair<int, int>ans = TS(v);
          cout<<ans.first<<space<<ans.second<<endl;
    }
    /*
     * In this problem relation between max difference and k is that the function strictly decreases first, reaches a minimum, and then strictly increases.
     * We can use ternary search to figure out the correct answer.
     * I have made a predicate function that calculate the maximum difference in the array at some value of k.
     * Then using ternary search I could find value of K that make the minimum difference between any two adjacent numbers.
     * Good Luck!
     * */
    return 0;
}








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
//int git_bit(int n, int i){
//    int mask = (1<<(i-1));
//    return (n&mask)>0;
//}
//
//void set_bit(int &n, int i){
//    int mask = (1<<(i-1));
//    n = (n | mask);
//}
//
//void clear_bit(int &n, int i){
//    int mask = (~(1<<(i-1)));
//    n=(n&mask);
//}
//
//void modify_bit(int &n, int i, int bit){
//    clear_bit(n,i);
//    int mask = (bit<<(i-1));
//    n = (mask|n);
//}
//
//void flip_bit(int &n, int i){
//    int mask = (1<<(i-1));
//    n = (n^i);
//}
//
//int least_bit(int n){
//    return (n&(-n));
//}
//
//bool power_of_2(int n){
//    return (n && !(n&(n-1)));
//}
//int count_ones(int n){
//    int count(0);
//    while (n--){
//        n = (n&(n-1));
//        count++;
//    }
//    return count;
//}
//bool is_palindrome(string s){
//    for(int i = 0; i <= s.size()/2; i++){
//        if(s[i]!=s[s.size()-1-i])
//            return 0;
//    }
//    return 1;
//}
int t =1,n;

int main() {
    init();
//    cin >>t;
    while (t--){
        cin >>n;
        ll ans = (ll)10e18;
        vector<ll>arr(n);
        for(int i = 0; i < n; i++)cin>>arr[i];


        for(int i = 0; i < (1<<(n-1)); i++){
            ll tempOR = 0, tempXOR = 0, mask = i;

            for(int j = 0; j < n; j++){
                tempOR |= arr[j];
                if((1&(mask>>j))){
                    tempXOR ^= tempOR;
                    tempOR = 0;
                }
            }
            tempXOR ^= tempOR;
            if(tempXOR < ans)ans=tempXOR;
        }
        cout<<ans;



    }
    return 0;
}



//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ "
*/
int git_bit(int n, int i){
    int mask = (1<<(i-1));
    return (n&mask)>0;
}

void set_bit(int &n, int i){
    int mask = (1<<(i-1));
    n = (n | mask);
}

void clear_bit(int &n, int i){
    int mask = (~(1<<(i-1)));
    n=(n&mask);
}

void modify_bit(int &n, int i, int bit){
    clear_bit(n,i);
    int mask = (bit<<(i-1));
    n = (mask|n);
}

void flip_bit(int &n, int i){
    int mask = (1<<(i-1));
    n = (n^i);
}

int least_bit(int n){
    return (n&(-n));
}

bool power_of_2(int n){
    return (n && !(n&(n-1)));
}
int count_ones(int n){
    int count(0);
    while (n--){
        n = (n&(n-1));
        count++;
    }
    return count;
}
bool is_palindrome(string s){
    for(int i = 0; i <= s.size()/2; i++){
        if(s[i]!=s[s.size()-1-i])
            return 0;
    }
    return 1;
}
int t =1,n,m;
int arr[10008];
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
//    cin >>t;
    while (t){
        cin >>m >>n;
        if(n==0||m==0)break;
        vector<int>nums(n);
        int cnt = 0;
        for(int &i : nums)cin >>i;
        cout<<"Sums of "<<m<<":"<<endl;
        set<string>ans;
        for(int i = 0; i < (1<<n); i++){
            int sum = 0;
            string s;
            for(int j = 0; j < n; j++){
                if(i&(1<<j)){
                    sum += nums[j];
                    s += to_string(nums[j]);
                    s+="+";
                }
            }
            s.pop_back();
            if(sum == m){
                ans.insert(s);
                cnt++;
            }
        }
        if(ans.empty())
            cout<<"NONE\n";
        else{

            for(auto it = ans.rbegin(); it!=ans.rend();it++){
                cout<<*it<<endl;
            }
        }
    }
//    fclose(stdout);
    return 0;
}



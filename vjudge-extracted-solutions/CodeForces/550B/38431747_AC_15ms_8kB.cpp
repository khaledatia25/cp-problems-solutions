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

int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
//    cin >>t;
    while (t--){
        int l,r,x;
        cin >>n >> l >>r >>x;
        int arr[n];
        for(int i = 0; i < n; i++)cin >>arr[i];
        int ans = 0;
        for(int i = 0; i < (1<<n); i++){
            int mask = i, sum = 0, y = 0, mi = INT_MAX, ma=INT_MIN, cnt=0;
            while(mask){
                if(mask&1) {
                    sum += arr[y];
                    mi = min(mi, arr[y]);
                    ma = max(ma, arr[y]);
                    cnt++;
                }
                mask = (mask>>1);
                y++;
            }
            if(sum >= l && sum<=r && (ma-mi)>=x && cnt >1)ans++;
        }
        cout<<ans;
    }
//    fclose(stdout);
    return 0;
}



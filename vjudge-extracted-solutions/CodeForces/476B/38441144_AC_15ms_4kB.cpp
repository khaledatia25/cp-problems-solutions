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
        string s1, s2;
        cin >>s1 >>s2;
        int sum_of_s1 = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == '+')sum_of_s1++;
            else sum_of_s1--;
        }
        int sum_of_s2 = 0, missing = 0;
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] == '?')missing++;
            else if(s2[i] == '+')sum_of_s2++;
            else sum_of_s2--;
        }
        int all = 0, arrived = 0;
        for(int i = 0; i < (1<<missing); i++){
            all++;
            int temp_sum = sum_of_s2;
            for(int j = 0; j < missing; j++){
                if(i&(1<<j))
                    temp_sum++;
                else
                    temp_sum--;
            }
            if(temp_sum == sum_of_s1)arrived++;
        }
        cout<<fixed<<setprecision(9)<<(double)( (double)arrived / (double)all );

    }
//    fclose(stdout);
    return 0;
}



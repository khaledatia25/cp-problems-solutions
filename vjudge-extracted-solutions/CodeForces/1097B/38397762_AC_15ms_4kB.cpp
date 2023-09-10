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
int t =1,n;
int arr[100];
int main() {
    init();
//    cin >>t;
    while (t--){
        cin >>n;
        int sum = 0;
        for(int i = 0; i < n; i++)cin>>arr[i];
        for(int i = 0; i <= (1<<n);i++){
            int mask = i,temp = 0;

            for(int j = 0; j < n;j++){
                if(mask&(1<<j)){
                    temp += arr[j];
                }else{
                    temp -= arr[j];
                }
            }

            if(temp%360==0){
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
    }
    return 0;
}



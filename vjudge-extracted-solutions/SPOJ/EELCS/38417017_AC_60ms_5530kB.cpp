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
int arr[10008];
int main() {
    init();
//    cin >>t;
    while (t--){
        string a, b;
        cin >>a >>b;
        vector<string>aa,bb;
        for(int i = 1; i < (1<<(a.size())); i++){
            int mask = i;
            string s;
            int y = 0;
            while (mask){
                if(mask&1)
                    s.push_back(a[y]);
                y++; mask = (mask >>1);
            }
//            cout<<s<<endl;
            aa.push_back(s);
        }
        for(int i = 1; i < ( 1<<(b.size()) ); i++){
            int mask = i;
            string s;
            int y = 0;
            while (mask){
                if(mask&1)
                    s.push_back(b[y]);
                y++; mask = (mask >>1);
            }
//            cout<<s<<endl;
            bb.push_back(s);
        }
        int ans = INT_MIN;
        for(string i : aa){
            int size = i.size();
            for(string j : bb){
                if (i == j) ans = max(ans, size);
//                cout<<i<<space<<j<<endl;
            }
        }
        if(ans > 0)
            cout<<ans;
        else
            cout<<0;
    }
    return 0;
}



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
    cin >>t;
    while (t--){
        cin >>n;
        set<int>s;
        int mx = INT_MIN;
        for(int i = 0; i <n; i++){
            cin >>m;
            s.insert(m);
            mx = max(m,mx);
        }
        bool ch;
        for(int i = 1; i <= 1024; i++){
            set<int>new_s;
            for(auto it = s.begin(); it != s.end(); it++){
                new_s.insert((i^(*it)));
            }
            ch = 1;
            for(auto it1 = s.begin(),it2 = new_s.begin();it1!=s.end()&&it2!=new_s.end();it1++,it2++){
                if(*it1!=*it2){
                    ch = 0;
                    break;
                }
            }
            if(ch) {
                cout << i << endl;
                break;
            }
        }
        if(!ch)
            cout<<-1<<endl;

    }
//    fclose(stdout);
    return 0;
}



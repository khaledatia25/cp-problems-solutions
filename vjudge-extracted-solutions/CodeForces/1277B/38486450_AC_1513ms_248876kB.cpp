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
ll t =1,n,m, arr[25];
char c;
void solve(){


}
bool pred(ll k, ll n){
    ll sum = 0, temp = n;
    while(temp){
        ll minus = min<ll>(temp,k);
        sum += minus;
        temp -= minus;
        temp -= temp / 10;
    }
    return sum*2>=n;
}

ll BS(){
    ll l = 0, h = n, ans = 0;
    while(h-l>1){
        ll mid = (l+h)/2;
        if(pred(mid, n)){
            h = mid;
        }else
            l = mid;
    }
    return h;
}

int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
    cin >>t;
    while (t--){
        cin >>n;
        map<int, int>mp;
        set<int>st;
        for(int i = 0; i < n; i++){
            int x;cin>>x;
            mp[x]++;
            st.insert(x);
        }
        int op = 0;
        for(auto it = st.rbegin(); it != st.rend(); it++){
            if(*it%2==0){
                op++;
                mp[*it/2]+=mp[*it];
                st.insert(*it/2);
            }
        }
        cout<<op<<endl;


    }

//    fclose(stdout);
    return 0;
}



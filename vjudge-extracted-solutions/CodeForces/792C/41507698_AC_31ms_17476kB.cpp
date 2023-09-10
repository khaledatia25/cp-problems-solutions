#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;

const int N = 500000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};  
string s;
int memo[N][4];
int sab7(int i, int mod, bool first = 1){
    if(i == (int) s.size()){
        return mod == 0 ? 0 : -1e6;
    }
    int & ret = memo[i][mod];
    if(~ret)
        return ret;
    
    int ch1=0;
    ch1 = first && s[i] == '0' ? 0 :   1+sab7(i+1, (mod+(s[i] - '0'))%3,  0);
    int ch2 = sab7(i+1, mod, first);

    return ret = max(ch1, ch2);
}   

void mesaa(int i, int mod, bool first = 1){
    if(i == (int) s.size())
        return;
    int  ret = sab7(i, mod);
    int ch1=0;
    ch1 = first && s[i] == 0 ? 0 :   1+sab7(i+1, (mod+(s[i] - 0))%3,  0);
    if(ret == ch1){
        cout<<s[i];
        mesaa(i+1, (mod+(s[i] - 0))%3,  0);
        return;
    }
    int ch2 = sab7(i+1, mod, first);
    if(ret == ch2){
        mesaa(i+1, mod, first);
        return;
    }
} 
int main() {
    KHALED_WALEED_ATTIA
    cin >>s;
    int sum =0;
    for(char c : s)
        sum += c-'0';
    int cnt[3] = {0};
    memset(memo, -1, sizeof memo);
    if(sab7(0, 0) == 0)
        if(s.find('0') != -1)
            cout<<0<<endl;
        else
            cout<<-1<<endl;
    else
        mesaa(0, 0);

    return 0;
}
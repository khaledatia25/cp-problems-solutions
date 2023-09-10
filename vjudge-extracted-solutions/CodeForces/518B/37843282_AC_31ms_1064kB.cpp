// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll = unsigned long long;

char opp(char c){
    if(c >= 'a' && c <= 'z')
        return (char)(c - 32);
    else
        return (char)(c + 32);
}

int main() {
    init();
    string s, t;
    cin >>s >>t;
    map<char, int> ss,tt;
    for(char & i : t){
        tt[i]++;
    }
    for(char & i : s){
        ss[i]++;
    }
    int y = 0, w = 0;
    for(char i = 'A'; i <= 'z'; i++){
        int d = min(ss[i], tt[i]);
        y+=d;
        ss[i] -= d;
        tt[i] -=d;
    }
    for(char i = 'A'; i<= 'Z'; i++){
        int d = min(ss[i]+ss[(char)(i+32)], tt[i]+tt[(char)(i+32)]);
        w += d;
    }
    cout<<y<<space<<w;
    return 0;
}








// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll = unsigned long long;
/*
              استعن بالله على المصاعب  
 
*/
char opp(char c){
    if(c >= 'a' && c <= 'z')
        return (char)(c - 32);
    else
        return (char)(c + 32);
}

int main() {
    init();
    string s;
    cin >>s;
    for(int i = 0; i < s.size(); i++){
        int n = s[i] - '0';
        if(n == 9 && i == 0)
            continue;
        if(n > 4)
            n = (9 - n);
        s[i] = (char)(n +'0');
    }
    cout<<s;
    return 0;
}








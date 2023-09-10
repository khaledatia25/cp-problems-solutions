#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
#define int long long
using namespace std;
void fileInput();
const int N = 100000+9;

int dx[] = {1, 0, -1, 0},
    dy[] = {0, -1, 0, 1};

const ll mod = 998244353;

class PalindromeMaker{
public:
string make(string baseString){
    map<char, int>mp;
    for(char i : baseString)
        mp[i]++;
    int o = 0;
    for(char i = 'A'; i <= 'Z';i++){
        if(mp[i]%2 != 0)
            o++;
    }
    if(o>1)
        return "";
    char center ='A';
    string ans;
    for(char i = 'A'; i <= 'Z';i++){
        if(mp[i]%2 != 0) {
            center = i;
            ans += string(mp[i]/2, i);
        }else
            ans += string(mp[i]/2, i);
    }
    string sna = ans; reverse(sna.begin(), sna.end());
    if(baseString.size()&1)
        return ans+center+sna;
    else
        return ans+sna;
}

};
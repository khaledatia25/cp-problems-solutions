#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;


const ll mod = 1000000007;

// Base Conversions
string letters = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int toInt(char c){return letters.find(c);}
int fromAnyBaseToDecimal(string in, int base){
    int res = 0;
    for(int i = 0; i < in.size(); i++){
        res *= base;
        res += toInt(in[i]);
    }
    return res;
}

string fromDecimalToAnyBase(int number, int base){
    if(number == 0)
        return 0;
    string res = "";
    for(;number;number/=base)
        res = letters[number%base]+res;
    return res;
}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    cin >>t;
    while(t--){
        ll s, d;
        cin >>s >>d;
        if(s<d||(s-d)%2){
            cout<<"impossible"<<endl;
            continue;
        }
        ll x = (s+d)/2;
        ll y = s - x;
        cout<<x<<space<<y<<endl;
    }
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

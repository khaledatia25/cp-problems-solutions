#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1},
        dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const ll mod = 1000000007;
string s1, s2;
int memo[109][109];
int rec(int i, int j){
    if(i == s1.size() || j == s2.size())
        return 0;
    int &ret = memo[i][j];

    if(~ret)
        return ret;

    if(s1[i] == s2[j])
        return ret = rec(i+1, j+1)+1;

    return ret = max(rec(i+1, j), rec(i, j+1));
}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    getline(cin, s1);
    int t = 1;
    while(s1!="#"){
        getline(cin ,s2);
        memset(memo, -1, sizeof memo);
        cout<<"Case #"<<t++<<": you can visit at most "<<rec(0, 0)<<" cities."<<endl;
        getline(cin, s1);
    }
//jjjjjj
    return 0;
}




void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

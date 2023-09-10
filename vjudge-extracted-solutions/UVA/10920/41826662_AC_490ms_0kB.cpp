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
int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int n, p;
    while(cin >>n >>p, n&&p){
        int row = (n+1)/2;
        int col = (n+1)/2;

        int cnt = 1;
        int i = 0, step = 0;
        while(cnt < p){
            if(i%2 == 0)
                step++;
            if(cnt + step > p)
                step = p - cnt;
            cnt += step;

            row += step * dx[i%4];
            col += step * dy[i%4];
            i++;
        }
        cout<<"Line = "<< row<<", column = "<<col<<"."<<endl;
    }
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
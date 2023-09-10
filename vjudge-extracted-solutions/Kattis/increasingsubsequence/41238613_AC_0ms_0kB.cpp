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
const int N=(int) 200 + 9;
int memo[N][N];
int a[N];
int n;

int lis(int i, int last){
    if(i >= n+1)
        return 0;

    int &ret = memo[i][last];
    if(~ret)
        return ret;

    int ch1 = 0, ch2 = 0;
    if(a[i]>a[last])
        ch1 = 1 + lis(i+1, i);
    ch2 = lis(i+1, last);

    return ret = max(ch1, ch2);
}
void printLIS(int i, int last){
    if(i >= n+1)
        return;

    int ch1 = 0, ch2 = 0;
    if(a[i]>a[last]){
        ch1 = 1 + lis(i+1, i);
    }
    ch2 = lis(i+1, last);

    if(ch1 > ch2){
        cout<<a[i]<<space;
        printLIS(i+1, i);
    }else{
        printLIS(i+1, last);
    }

}
int main() {
    KHALED_WALEED_ATTIA
//    fileInput();
    while (cin >>n,n){
        a[0] = -1;
        for(int i = 1; i <= n; i++)
            cin >>a[i];
        memset(memo, -1, sizeof memo);
        int mx = lis(1, 0);
        cout<<mx<<space;
        printLIS(1, 0);
        cout<<endl;

    }
    return 0;
}
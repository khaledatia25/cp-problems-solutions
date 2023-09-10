#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
#define int long long
using namespace std;
void fileInput();
const int N = 100000+9;
int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, -1, 1};

const ll mod = 998244353;
int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    function<int(int,int)>powercnt;
    powercnt = [](int a, int n)->int{
        int cnt=0;
        int cur = 1;
        while(cur<=n){
            if(cur==n)
                return cnt;
            cnt++;
            cur*=a;
        }
        return 0;
    };
    function<int(int)>ans;
    ans = [&powercnt](int num) -> int{
        int ret = 1;
        bool neq=0;
        if(num<0)
            neq=1, num*=-1;
        for(int i = 2; i * i <= num; i++){
            if(num%i==0){
                int a = powercnt(i, num);
                int b = powercnt(num/i, num);
                if(a&1)
                    ret= max(ret, a);
                else
                    ret=neq?ret: max(ret, a);
                if(b&1)
                    ret= max(ret, b);
                else
                    ret=neq?ret:max(ret, b);
            }
        }
        return ret;
    };
    int n;

    while(cin>>n, n){
        cout<<ans(n)<<endl;
    }
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
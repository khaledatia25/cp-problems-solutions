#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
using namespace std;
void fileInput();
const int N = 10000000+9;
int dx[] = {1, 1, -1, -1},
        dy[] = {1, -1, -1, 1};
const ll mod = 1000000007;

bool notPrime[N];
int prevPrime[N];
void sieve(){
    notPrime[0]=notPrime[1]=1;
    for(int i = 2; i*i < N; i++){
        if(!notPrime[i]){
            for(int j = i*i; j < N; j+= i){
                notPrime[j]=1;
            }
        }
    }
    prevPrime[0]=prevPrime[1] = 0;
    prevPrime[2] = 2;
    int previous = 3;
    for(int i = 3; i < N; i++){
        if(notPrime[i]){
            prevPrime[i] = previous;
        }else{
            prevPrime[i] = i;
            previous = i;
        }
    }
}


int32_t main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int n;
    cin >>n;
    int ans = min(15, 3000/n + (3000%n != 0));
    cout<<ans<<endl;
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
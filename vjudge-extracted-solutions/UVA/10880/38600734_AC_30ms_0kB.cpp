//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define MOD 1000000007
#define dbl double
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

int t =1,n,m=1, arr[25];
const int N = 1e7+6;
bool composite[N]={0};
int prevPrimes[N];
void sieve(){
    composite[0]=composite[1]=1;
    for(int i = 2; i*i < N;i++){
        if(!composite[i]) {
            for (int j = i * i; j < N; j += i) {
                composite[j] = 1;
            }
        }
    }
    prevPrimes[0]=prevPrimes[1]=0;
    prevPrimes[2]=2;
    int p = 3;
    for(int i = 3; i< N;i++){
        if(composite[i])
            prevPrimes[i] = p;
        else {
            prevPrimes[i] = i;
            p = i;
        }
    }
}

void solve(int cnt) {
    int c, r;
    cin >>c >>r;
    int diff = c-r;
    cout<<"Case #"<<cnt<<":";
    if(diff==0){
        cout<<space<<0<<endl;
        return;
    }
    set<int>st;
    for(int i = 1; i*i<=diff;i++){
        if(diff%i==0){
            st.insert(i);
            st.insert(diff/i);
        }
    }
    for(auto it = st.begin(); it != st.end(); it++){
        if(*it>r)cout<<space<<*it;
    }
    cout<<endl;
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
    cin >>t;
    int cnt = 1;
    while (t--){
        solve(cnt++);
    }

//    fclose(stdout);
    return 0;
}



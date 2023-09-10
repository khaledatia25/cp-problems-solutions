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
const int N = 1e6+5;
bool composite[N]={0};
int prevPrimes[N];
int ans[N] = {0};
vector<int>primes;
void sieve(){
    composite[0]=composite[1]=1;
    for(int i = 2; i*i < N;i++){
        if(!composite[i]) {
            for (int j = i * i; j < N; j += i) {
                composite[j] = 1;
            }
        }
    }
    for(int i = 2; i< N;i++){
        if(!composite[i])
            primes.emplace_back(i);

    }
}
void is_circular(int num){
    string s = to_string(num);
    vector<int>v;
    bool circular = 1;
    for(int i = 0; i < s.size(); i++){
        int nn = stoi(s);
        v.push_back(nn);
        if (composite[nn]) {
            circular = 0;
            break;
        }
        s.push_back(s[0]);
        s = s.substr(1,s.size()-1);
    }
    if(circular){
        for(int i : v)
            ans[i]=1;
    }
}
void solve() {
    for(int i : primes){
        is_circular(i);
    }
    for(int i = 1; i<N;i++)ans[i] += ans[i-1];
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
//    cin >>t;
    sieve();
    solve();
    while (t){
        cin >>n;
        if(n==-1)break;
        cin >>m;
        int a = ans[m]-ans[n-1];
        if(a == 1)
            cout<<a<<" Circular Prime."<<endl;
        else if(a==0)
            cout<<"No Circular Primes."<<endl;
        else
            cout<<a<<" Circular Primes."<<endl;
    }

//    fclose(stdout);
    return 0;
}



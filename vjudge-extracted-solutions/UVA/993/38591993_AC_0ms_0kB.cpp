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

bool is_prime(int n){
    if(n == 2)
        return 1;
    if(n == 1 || n%2 == 0)
        return 0;
    for(int i = 3; i*i <= n; i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
void prime_factorization(int n,vector<int>&v){
    int factor = 1;
    for(int i = 9; i>1;i--){
        while(n%i==0){
            v.push_back(i);
            n /=i;
        }
    }
    if(n<10&&n!=1)
        v.push_back(n);
}

void solve() {
    cin >>n;
    vector<int>v;
    if(n == 1)
        cout<<1<<endl;
    else if(n==0){
        cout<<0<<endl;
    }else
    {
        prime_factorization(n, v);
        int ans=1;
        string anss;
        if(v.empty()){
            cout<<-1<<endl;
        }else{
            sort(v.begin(),v.end());
            for(int i : v){
                ans*=i;
                anss.push_back(i+'0');
            }
            if(ans==n)
                cout<<anss<<endl;
            else
                cout<<-1<<endl;
        }

    }
}
int main() {
    init();
//    freopen("input.in","r",stdout);
//    freopen("out.out","w",stdout);
    cin >>t;
    while (t--){
        solve();
    }

//    fclose(stdout);
    return 0;
}



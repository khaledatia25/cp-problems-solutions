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
    auto isPrime = [](int n){
        if(n == 1)
            return  false;
        for(int i = 2; i*i<=n;i++){
            if(n%i==0)
                return false;
        }
        return true;
    };
    auto ans = [](int n){
        return (ll)(1LL<<(n-1))*((1LL<<n)-1LL);
    };
    auto isPerfect = [&ans](int n){
        vector<int>a1, a2;
        int n1= (1LL<<(n-1));
        int n2 = ((1LL<<n)-1LL);
        for(int i = 1; i*i <= n1; i++){
            if(n1%i==0) {
                a1.push_back(i);
                if(i != n1/i)
                    a1.push_back(n1/i);
            }
        }
        for(int i = 1; i*i <= n2; i++){
            if(n2%i==0) {
                a2.push_back(i);
                if(i != n2/i)
                    a2.push_back(n2/i);
            }
        }
        set<int>st;
        for(int i : a1){
            st.insert(i);
            for(int j : a2){
                st.insert(j);
                st.insert(i*j);
            }
        }
        int aaa=ans(n);
        st.erase(aaa);
        for(int i : st)
            aaa-=i;
        if(aaa==0)
            return 1;
        else
            return 0;
    };
    int n;
    while(cin>>n, n){
        if(isPrime(n)){

            if(isPerfect(n))
                cout<<"Perfect: "<<ans(n)<<"!"<<endl;
            else
                cout<<"Given number is prime. But, NO perfect number is available."<<endl;
        }
        else
            cout<<"Given number is NOT prime! NO perfect number is available."<<endl;
    }
    return 0;
}

void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
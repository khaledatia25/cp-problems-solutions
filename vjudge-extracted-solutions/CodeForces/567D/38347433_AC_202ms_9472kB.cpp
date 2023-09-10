//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

int t=1, n,k,m,a,x, max_weight = 13;
vector<vector<ll>>v;
ll sum = 0;



vector<int> friends;
int main() {
    init();
//    cin >>t;
    while(t--){
        cin >>n >>k >>a >>m;
        set<int>st;
        st.insert(0);st.insert(n+1);
        int ships = (n+1)/(a+1);
        for(int i = 0; i < m; i++){
            cin >>x;
            int l = *(--st.lower_bound(x));
            int u = *st.lower_bound(x);
            st.insert(x);
            ships -= (u-l)/(a+1);
            ships += (x-l)/(a+1);
            ships += (u-x)/(a+1);
            if(ships < k){
                cout<<i+1;
                return 0;
            }
        }
        cout<<-1;

    }

    return 0;
}



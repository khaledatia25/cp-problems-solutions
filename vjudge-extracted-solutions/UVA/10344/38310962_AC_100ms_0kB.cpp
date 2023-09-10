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

ll t=1, n,x, max_weight = 13,m;
int a[5];
bool found = 0;
bool p(int idx, int res = 0){
    if(idx >= 5)
        return (res == 23);
    return p(idx+1,res+a[idx]) || p(idx+1,res-a[idx]) || p(idx+1,res*a[idx]);
}

int main() {
    init();
//    cin >>t;
    while(t){
        int sum = 0;
        for(int i = 0; i < 5; i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum == 0)break;
        found = 0;
        sort(a,a+5);
        bool co = true;
        while (co){
            found = p(1,a[0]);
            if(found)
                break;
            co =  next_permutation(a,a+5);
        }
        if(found)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;

    }

    return 0;
}

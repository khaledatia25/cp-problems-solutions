//// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
#define mx_str "99999999999999999999999999"
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

ll t=1, n,x, max_weight = 13,m;
int a[5];
int visit[5];
bool found = 0;
void p(int idx, int res = 0,int first = 0){
    if(idx >= 5) {
        found = found||(res==23);
        return;
    }
    if(found)
        return;
    for(int i = 0; i < 5;i++){
        if(visit[i])continue;
        visit[i] = 1;
        if(first){
            p(idx+1,res+a[i],1);
            p(idx+1,res-a[i],1);
            p(idx+1,res*a[i],1);
        }else{
            p(idx+1,a[i],1);
        }
        visit[i] = 0;
    }


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
        p(0);
        if(found)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;

    }

    return 0;
}

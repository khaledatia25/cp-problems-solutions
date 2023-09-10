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



int a[100005], b[100005];
char maze[100][100];
int visit[100][100] = {0};
ll t=1, n,x, max_weight = 13,m;
int xx , yy;
int arr[100005];
vector<ll>lucky;
void p(ll num = 0){
    if(num > 1e9)
        return;
    if(num)
        lucky.push_back(num);
    p(num*10+4);
    p(num*10+7);
}

int main() {
    init();
//    cin >>t;
    while(t--){
        cin >>n;
        p(0);
        sort(lucky.begin(), lucky.end());
        for(int i = 0; i < lucky.size(); i++)
            if(lucky[i] == n){
                cout<<i+1;
                return 0;
            }

    }

    return 0;
}
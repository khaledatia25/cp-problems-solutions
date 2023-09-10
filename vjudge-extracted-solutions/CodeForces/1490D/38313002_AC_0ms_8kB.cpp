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
int a[105];
int ans[105];
int visit[105] = {0};
void p(int start,int end,int d = 0){
    int m = start;
    if(start > end)
        return;
    for(int i = start; i <= end;i++){
        if(a[i]>a[m])m=i;
    }
    ans[m] = d;
    p(start, m-1, d+1);
    p(m+1,end, d+1);

}

int main() {
    init();
    cin >>t;
    while(t--){
      cin >>n;
      for(int i = 0; i < n; i++)cin >>a[i];
      p(0,n-1,0);
      for(int i = 0; i < n; i++)cout<<ans[i]<<space;
      cout<<endl;
    }

    return 0;
}

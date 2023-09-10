// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
#define ll long  long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
ll t = 1, n,m,k, arr[1000005], matrix1[105][105], matrix2[105][105], visted[105][105]= {0};

int p(int nn){
    if(nn == 1)
        return 1;
    if(nn%2 == 0)return 1 + p(nn/2);
    else return 1 + p(3*nn+1);

}
int main() {
    init();
//    cin >>t;
    while(t--){
        cin >>n;
        cout<<p(n);
    }

    return 0;//
}



#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1},
        dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const ll mod = 1000000007;
const int N = 1000+9;
int memo[N][N], p[N], a[N];
int l;
int cuts[N];
int n;
string s;
int rec(int i, int j){
   if(i >= j)
       return 0;

   int & ret = memo[i][j];
   if(~ret)
       return ret;

   int ch1 = rec(i+1, j-1) + (s[i] != s[j]);
   int ch2 = 1 + rec(i+1, j);
   int ch3 = 1 + rec(i, j-1);
   return ret = min({ch1, ch2, ch3});
}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int t;
    cin >>t;
    int Case = 1;
    while(t--){
        memset(memo, -1, sizeof memo);
        cin >>s;
        cout<<"Case "<<Case++<<": ";
        cout<<rec(0, s.size() - 1)<<endl;
    }
    return 0;
}









;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;  ;;;;;;  ;;;;  ;;;;;;;;;;  ;;;;;;;;;;;    ;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;              ;;;             ;;;;;;;;;
;;  ;;;;  ;;;;;;  ;;;;;;;;;;  ;;;;;;;;;;  ;;  ;;;;;;;;;;;;  ;;;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;   ;;;;;;;;;   ;;;;;;;
;;  ;;  ;;;;;;;;  ;;;;;;;;;;  ;;;;;;;;;  ;;;;  ;;;;;;;;;;;  ;;;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;   ;;;;;;;;;;   ;;;;;;
;;    ;;;;;;;;;;  ;;;;;;;;;;  ;;;;;;;;  ;;;;;;  ;;;;;;;;;;  ;;;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;   ;;;;;;;;;;   ;;;;;;
;;  ;;;;;;;;;;;;              ;;;;;;;            ;;;;;;;;;  ;;;;;;;;;;;;;;;           ;;;;;;   ;;;;;;;;;;;   ;;;;;
;;    ;;;;;;;;;;  ;;;;;;;;;;  ;;;;;;  ;;;;;;;;;;  ;;;;;;;;  ;;;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;   ;;;;;;;;;;;   ;;;;;
;;  ;;  ;;;;;;;;  ;;;;;;;;;;  ;;;;;  ;;;;;;;;;;;;  ;;;;;;;  ;;;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;   ;;;;;;;;;;;   ;;;;;
;;  ;;;;  ;;;;;;  ;;;;;;;;;;  ;;;;  ;;;;;;;;;;;;;;  ;;;;;;  ;;;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;   ;;;;;;;;;;;   ;;;;;
;;  ;;;;;;  ;;;;  ;;;;;;;;;;  ;;;  ;;;;;;;;;;;;;;;;  ;;;;;  ;;;;;;;;;;;;;;;  ;;;;;;;;;;;;;;;   ;;;;;;;;;;;  ;;;;;;
;;  ;;;;;;;;  ;;  ;;;;;;;;;;  ;;  ;;;;;;;;;;;;;;;;;;  ;;;;             ;;;;              ;;;               ;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
void fileInput(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

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
const int N = 100+9, K = 1000+9;
int racks[N];
map<ll, ll>memo;
map<ll, bool>vis;
ll naruto(ll n){
   if(n<3)
       return n;
   if(vis[n])
       return memo[n];
   vis[n] = 1;
   ll ch1 = n;
   ll ch2 = naruto(n/2) + naruto(n/3) + naruto(n/4);

    return memo[n] = max(ch1, ch2);
}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    ll n;
    while(cin >>n){
        cout<<naruto(n)<<endl;
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

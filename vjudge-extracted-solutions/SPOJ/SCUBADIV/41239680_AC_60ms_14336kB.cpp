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
const int N=(int) 1000 + 9, T = 30, A = 90;
int memo[N][T][A];
int o[N], ni[N], w[N];
int n, t, a;
int diver(int i, int o_needed,int ni_needed){
    if(o_needed == 0 && ni_needed == 0)
        return 0;
    if(i == n)
        return  1e6;
    int &ret = memo[i][o_needed][ni_needed];
    if(~ret)
        return ret;
    int ch1 = INT_MAX, ch2 = INT_MAX;
    ch1 = w[i] + diver(i+1, max(0, o_needed - o[i]), max(0, ni_needed - ni[i]));
    ch2 = diver(i+1, o_needed, ni_needed);

    return ret =  min(ch1, ch2);

}
int main() {
    KHALED_WALEED_ATTIA
    fileInput();
    int tt;
    cin >>tt;
    while(tt--){
        memset(memo, -1, sizeof memo);
        cin >>t >>a;
        cin >>n;
        for(int i = 0; i < n; i++)
            cin >>o[i] >>ni[i] >>w[i];
        cout<<diver(0, t, a)<<endl;
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

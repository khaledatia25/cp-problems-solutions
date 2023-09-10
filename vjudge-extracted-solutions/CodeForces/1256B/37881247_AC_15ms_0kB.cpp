// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space " "
using namespace std;
void init(){fast;}
using ll =  long long;
/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/

int main() {
    init();
    int t = 1;
    cin >>t;
    while(t--){
        int n; cin >>n;
        int arr[n], swaped[n];
        for(int i = 0; i < n; i++)cin >>arr[i], swaped[i] = 0;
        int op = 0;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j < n-1; j++){
                if(arr[j] > arr[j + 1] && swaped[j]==0){
                    swap(arr[j], arr[j+1]);
                    swaped[j]=1;
                }
            }
        }
        for(int i : arr)cout<<i<<space;
        cout<<endl;
    }
    return 0;
}








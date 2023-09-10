       /* Do it! */
      /*  OMAR  */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

set<int>used;
int c = 1;

bool isGoingToOne(int n){
    return n == 2 || n == 4 || n == 6 || n == 10 || n == 12 || n == 16;
}

void print(vector<int>&res){
    for (int j = 0; j < res.size(); j++){
        if(j == 0)
            printf("%i", res[j]);
        else
            printf(" %i", res[j]);
    }
    printf("\n");
}

void DFS(vector<vector<int>>&arr, vector<int>res, int f, int n){
    for (int i = 0; i < arr[f].size(); i++){
        if(res.size() == n && isGoingToOne(res.back())){
            print(res);
            used.erase(res.back());
            res.pop_back();
            return;
        }
        if(used.find(arr[f][i]) == used.end()){
            used.emplace(arr[f][i]);
            res.emplace_back(arr[f][i]);
            DFS(arr, res, arr[f][i]-1, n);
            used.erase(res.back());
            res.pop_back();
        }
    }

}

int main() {
//    o:
    bool newLine = false;
    int prim[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int n;
    while(cin>>n){
        if(newLine)
            printf("\n");
        newLine = true;
        vector<int>res;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 11 && prim[j]-i-1 <= n; j++){
                if(i+1 < prim[j] && prim[j] -i-1 != i+1){
                    arr[i].emplace_back(prim[j] -i-1);
                }
            }
        }

        printf("Case %i:\n", c);
        c++;
        if(n == 0)
            continue;
        used.clear();
        used.emplace(1);
        res.emplace_back(1);
        DFS(arr, res, 0, n);
    }
//    goto o;
    return 0;
}
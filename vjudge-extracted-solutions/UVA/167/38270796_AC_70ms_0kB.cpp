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
int chessboard[8][8];
int attacked[8][8];
int boardNums[8][8];
void markAttacked(int x, int y){
    for(int i = 0; i < 8; i++)
        attacked[x][i]++;
    for(int i = 0; i < 8; i++)
        attacked[i][y]++;
    for(int i = 0; i < 8; i++){
        if(x+i < 8 && y+i < 8)
            attacked[x+i][y+i]++;
        if(x-i >= 0 && y-i >= 0)
            attacked[x-i][y-i]++;
        if(x-i >= 0 && y+i < 8)
            attacked[x-i][y+i]++;
        if(x+i < 8 && y-i >= 0)
            attacked[x+i][y-i]++;
    }
}
void removeMark(int x,int y){
    for(int i = 0; i < 8; i++)
        attacked[x][i]--;
    for(int i = 0; i < 8; i++)
        attacked[i][y]--;
    for(int i = 0; i < 8; i++){
        if(x+i < 8 && y+i < 8)
            attacked[x+i][y+i]--;
        if(x-i >= 0 && y-i >= 0)
            attacked[x-i][y-i]--;
        if(x-i >= 0 && y+i < 8)
            attacked[x-i][y+i]--;
        if(x+i < 8 && y-i >= 0)
            attacked[x+i][y-i]--;
    }
}

int p(int x, int y, int sum = 0, int queens = 0){
    if(queens == 8)
        return sum;
    if(y >= 8)
        y = 0, x++;
    if(x >=8)
        return INT_MIN;
    int sum1=0, sum2=0;
    if(attacked[x][y] == 0){
        markAttacked(x, y);
        sum1=p(x, y+1, sum+boardNums[x][y], queens+1);
        removeMark(x,y);
    }
    sum2 = p(x, y+1, sum, queens);
    if(sum1)
        return max(sum1, sum2);
    else
        return sum2;

}

int main() {
    init();
    cin >>t;
    while(t--){
        int counter = 1;
        for(int i = 0; i < 8;i++)
            for(int j = 0; j < 8;j++)
                cin>>boardNums[i][j],attacked[i][j]=0,chessboard[i][j]=0;
        cout<<setw(5)<<setiosflags(ios::right)<<p(0,0)<<endl;
    }

    return 0;
}
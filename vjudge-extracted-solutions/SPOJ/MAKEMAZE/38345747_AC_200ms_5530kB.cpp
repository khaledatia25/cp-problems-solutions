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
ll t=1, n, max_weight = 13,m;
int xx , yy;
bool p(int x, int y,int doors=0, int cnt = 0){
    if(x >= n || x < 0 || y >= m || y < 0)
        return 0;
    if(doors != 2)
        return 0;
    if(maze[x][y] == '#' || visit[x][y])
        return 0;
    if((x != xx || y != yy) && (x == 0 || x == n - 1 || y == 0 || y == m-1)){
        return 1;
    }
    visit[x][y] = 1;
    return p(x-1, y, doors) || p(x+1,y, doors) || p(x, y-1, doors) || p(x, y+1, doors);


}

int main() {
    init();
    cin >>t;
    while(t--){
        cin >>n >>m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >>maze[i][j], visit[i][j] = 0;
        int  cnt=0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(i==0&&maze[i][j] == '.')cnt++, xx = i, yy = j;
                else if(j == 0&&maze[i][j] == '.')cnt++,xx = i, yy = j;
                else if(i == n-1&&maze[i][j] == '.')cnt++,xx = i, yy = j;
                else if(j == m-1&&maze[i][j] == '.')cnt++,xx = i, yy = j;
            }
        if(p(xx,yy, cnt))
            cout<<"valid"<<endl;
        else
            cout<<"invalid"<<endl;
    }

    return 0;
}


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
int a[5];
bool found = 0;
int arrive = 0, not_arrive = 0;
void p(int idx,string  s,int ans,int cnt=0){
    if(idx >= s.size()) {
        if(cnt == ans)
            arrive++;
        else
            not_arrive++;
        return ;
    }
    if(s[idx] == '+')
         p(idx+1,s,ans,cnt+1);
    else if(s[idx] == '-')
         p(idx+1,s,ans,cnt-1);
    else {
        p(idx + 1, s, ans, cnt - 1);
        p(idx + 1, s, ans, cnt + 1);
    }
}

int main() {
    init();
//    cin >>t;
    while(t--){
        string sent, received;
        cin >>sent >>received;
        int cnt = 0;
        for(int i = 0; i < sent.size(); i++)
            if(sent[i] == '+')cnt++;
            else cnt--;
        p(0,received,cnt,0);
        cout<<fixed<<setprecision(9)<<(double)arrive/(double )(arrive+not_arrive);


    }

    return 0;
}
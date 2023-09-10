/*
     To infinity and beyond
*/    
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define dbl double
#define ll long  long
#define MOD 1000000007
#define setting(x, i) memset(x, i, sizeof(x))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mkV(v, type, l, i) v=vector<type>(l, i)
#define prefix(a, n) for(int i = 1; i < n; i++)a[i]+=a[i-1]
#define getV(v) for(auto& i : v)cin>>i
#define endl "\n"
#define fr(a,b) for(int a=0;a<=b;a++)
#define frh(a,b) for(int a=1;a<=b;a++)
using namespace std;
const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1};
const int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
// const int N = 200005;
ll inf = 1e9+1;
ll n,m,k,y;
int t=1; 
const int OO = 0x3f3f3f3f;
const int SZ = 1e5+5;
// int arr[SZ];
set<int>st;
ll x, minus, temp, ans, l, r,d;
ll const N = 1e12+1;
int memo[2022][2022];
string a, b;
int MEMO(int i, int j){
   if(i == a.size())
        return b.size() - j;
    if(j == b.size())
        return a.size() - i;

    int &ret = memo[i][j];

    if(~ret)
        return ret;

    if(a[i] == b[j])
        return ret = MEMO(i+1,j+1);

    int I, D, R;
    I = 1+MEMO(i, j+1);  // Insert
    D = 1+MEMO(i+1, j);  // Delete
    R = 1+MEMO(i+1,j+1); // Replace            

    return ret = min({I,D,R});         
}
int idx=0;
void MEMOTracing(int i, int j){
    if(i == a.size()){
        for(int k = j; k < b.size(); k++){
            cout<<"INSERT "<<i+idx+1<<space<<b[k]<<endl;
            idx++;
        }
        return;
    }
    if(j == b.size()){
        for(int k = i; k < a.size(); k++){
            cout<<"DELETE "<<k+idx+1<<endl;
            idx--;
        }
        return;
    }
    if(a[i] == b[j]){
        MEMOTracing(i+1,j+1);
        return;
    }
    int I, D, R;
    I = 1+MEMO(i, j+1);  // Insert
    D = 1+MEMO(i+1, j);  // Delete
    R = 1+MEMO(i+1,j+1); // Replace  
    int ret = min({I,D,R});
    if(ret == I){
        cout<<"INSERT "<<i+idx+1<<space<<b[j]<<endl;
        idx++;
        MEMOTracing(i,j+1);
    }else if(ret == D){
        cout<<"DELETE "<<i+idx+1<<endl;
        idx--;
        MEMOTracing(i+1,j);
    }else{
        cout<<"REPLACE "<<i+idx+1<<space<<b[j]<<endl;
        MEMOTracing(i+1,j+1);
    }
}

int main() {
    KHALED_WALEED_ATTIA
    // cin >>t;
    int cnt=1;
    // cout<<mp.size()<<endl;
    while(t--){
        cin >>a >>b;
        setting(memo,-1);
        cout<<MEMO(0,0)<<endl;
        MEMOTracing(0,0);
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long  long
#define int long  long
#define OO 1e18
#define oo 1e9
using namespace std;
void fileInput();
const int N = 6000000+9;
int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};
const ll mod = 1e9+7;
set<string>st;
vector<char>v;
vector<bool>taken;
bool rec(int i, vector<char> ans = {}){
    if(i == v.size()){
        for(int k = 0; k < ans.size(); k++){
            cout<<ans[k];
            if(k<ans.size()-1)
                cout<<space;
        }
        cout<<endl;
        return 1;
    }
    bool ret = 0;
    for(int k = 0; k < v.size(); k++){
        if(!taken[k]){
            taken[k] = 1;
            bool valid = 1;
            string temp;
            temp.push_back(v[k]);
            temp.push_back('<');
            for(char i : ans){
                string f = temp;
                f.push_back(i);
                if(st.count(f)){
                    valid = 0;
                    break;
                }
            }    

            if(valid){
                ans.push_back(v[k]);
                ret = rec(i+1, ans) || ret;
                ans.pop_back();
            }
            taken[k] = 0;
        }
    }
    return ret;
}
int32_t main() {
    KHALED_WALEED_ATTIA
    function<void(int)>sol;
    fileInput();
    int n, m, k;
    sol = [&](int test) -> void {
        v.clear();
        st.clear();
        taken.clear();
        string s;
        getline(cin, s);
        getline(cin, s);
        char c;
        stringstream ss(s);
        while(ss>>c)v.push_back(c);
        getline(cin, s);
        stringstream ss1(s);
        string r;
        while(ss1 >>r)st.insert(r);
        taken.assign(v.size(), 0);
        sort(all(v));
        if(!rec(0)){
            cout<<"NO"<<endl;
        }
        

    };
    int t = 1;
    // cin >>t;
    int test = 1;
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss>>t;
    while(t--){
        sol(test++);
        if(t)cout<<endl;
    }

    return 0;
}


void fileInput(){
#ifndef ONLINE_JUDGE
   freopen("../input.txt", "r", stdin);
   freopen("../output.txt", "w", stdout);
#endif
}
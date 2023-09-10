// To infinity and beyond
#include <bits/stdc++.h>
#define fast cin.tie(0),cin.sync_with_stdio(0),cout.tie(0)
#define space ' '
#define ll long long
using namespace std;
void init(){fast;}

/*
             "وَتَوَكَّلْ عَلَى ٱلْحَىِّ ٱلَّذِى لَا يَمُوتُ"
*/
int main() {
    init();
    int t = 1;
//    cin >>t;
    while(t--){
       string s; cin >>s;
       stack<char>st;
       for(int i = 0; i < s.size(); i++){
           if(!st.empty() && s[i] == st.top())
               st.pop();
           else
               st.push(s[i]);
       }
       vector<char>v;
        while(!st.empty())
            v.push_back(st.top()), st.pop();
        for(int i = v.size() - 1; i >= 0; i--)cout<<v[i];
    }
    return 0;
}
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
    string s;
    cin >>s;
    vector<char>v(s.size());
    v[s.size() - 1] = s[s.size() - 1];
    for(int i = s.size() - 2; i >= 0; i--)
        v[i] = min(s[i], v[i+1]);
    stack<char>st;
    for(int i = 0; i < s.size(); i++){
        while(!st.empty() && st.top() <= v[i]){
            cout<<st.top();
            st.pop();
        }
        st.push(s[i]);
    }
    while(!st.empty())
        cout<<st.top(), st.pop();
    return 0;
}
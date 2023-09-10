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
int a[100005];
vector<vector<int>>v(1008);
int cnt = 0;
void p(int rule_idx,vector<string>words, string rule,string password = ""){
        if(rule_idx >= rule.size()) {
            cout<<password<<endl;
            return;
        }
        if(rule[rule_idx] == '0'){
            for(int i = 0;i<10;i++){
                p(rule_idx+1, words, rule, password+ to_string(i));
            }
        }else{
            for(int i = 0; i < words.size(); i++){
                p(rule_idx+1, words,rule, password+words[i]);
            }
        }
}

int main() {
    init();
//    cin >>t;
    while(cin >>n){
        vector<string>words(n);
        for(string &s : words)cin >>s;
        cin >>t;
        vector<string>rules(t);
        for(string &s : rules)cin >>s;
        for(string i : rules){
            cout<<"--"<<endl;
            p(0,words,i);
        }

    }

    return 0;
}
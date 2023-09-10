#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define space " "
#define endl "\n"
#define ll long  long
void fileInput();
using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1},
        dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
const ll mod = 1000000007;

/*



*/

class MessageMess{
    ll memo[55][55];
    set<string>st;
    string msg;
    string returned="";
    int n;
public:
    ll rec(int i,int s_size, string s, string final){
        if(i == n){
            if(s_size == msg.size()){
                returned = final;
                return 1;
            }
                return 0;
        }
        ll &ret = memo[i][s_size];

        if(~ret)
            return ret;

        ret = 0;
        s.push_back(msg[i]);
        if(st.count(s))
            ret += rec(i+1, s_size+s.size(), "", final+s+" ");

        ret += rec(i+1, s_size, s, final);

        return ret;
    }

    string restore(vector<string>dictionary, string message){
        this->n = message.size();
        memset(memo, -1, sizeof memo);
        this->msg = message;
        for(auto i : dictionary)st.insert(i);
        ll ans = rec(0,0, "", "");
        cout<<ans<<endl;
        if(ans==0){
            return "IMPOSSIBLE!";
        }else if(ans == 1){
            returned.pop_back();
            return returned;
        }else{
            return "AMBIGUOUS!";
        }

    }
};
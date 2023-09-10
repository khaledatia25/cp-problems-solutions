/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>

#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl '\n'

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define prec(n) cout << fixed << setprecision(n)
#define countbits(n) __builtin_popcount(n)

#define ll long long
#define int long long
#define OO (ll)1e18
#define oo (ll)1e9
#define angle(a) (atan2((a).imag(), (a).real()))

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class F>
using ordered_map = tree<T, map<T, F>, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class F>
using ordered_multimap = tree<T, map<T, F>, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void fileInput(/*Hello World*/);

typedef complex<double> point;
const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
        dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
//const ll mod = 998244353;
const int sz = 1e6;

const int K = 500 + 9;
const ll N = 1e5 + 9;
using ld = long double;
ll dp[N][11][3];
vector<int> g[N];
int n, m, k, x;
const int MAX_CHAR = 26;

struct TRIE {
    TRIE *child[MAX_CHAR];
    bool isLeaf;

    TRIE() {
        memset(child, 0, sizeof child);
        isLeaf = false;
    }

    void insert(string &str, int i = 0) {
        if (i == str.size())isLeaf = true;
        else {
            int cur = str[i] - 'a';
            if (child[cur] == 0) {
                child[cur] = new TRIE();
            }
            child[cur]->insert(str, i + 1);
        }
    }

    bool wordExist(string &str, int i = 0) {
        if (i == str.size())return isLeaf;

        int cur = str[i] - 'a';
        if (child[cur] == 0) {
            return false;
        }
        return child[cur]->wordExist(str, i + 1);
    }


    void prefix(string &str, vector<string> &v, string temp, int i = 0) {
        if (i >= str.size()) {
            if (i > str.size() && isLeaf) {
                v.push_back(temp);
            }
            for (int k = 0; k < 26; k++) {
                if (child[k] == 0)continue;
                child[k]->prefix(str, v, temp + char('a' + k), i + 1);
//                cout << temp << endl;
            }
            return;
        }
        int cur = str[i] - 'a';
        if (child[cur] == 0)return;

        child[cur]->prefix(str, v, temp + str[i], i + 1);
    }

    bool prefixExist(string &str, int i = 0) {
        if (i == str.size())return true;

        int cur = str[i] - 'a';
        if (child[cur] == 0)return false;

        return child[cur]->prefixExist(str, i + 1);
    }
};

void init() {}

void elmtarshm(int tc) {
    cin >> n;
    TRIE tr;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        tr.insert(s);
    }
    vector<string> ans;
    int q;
    cin >> q;
    int cnt = 1;
    string s = "setter";
//    cout << tr.wordExist(s) << endl;
    while (q--) {
        string s;
        cin >> s;
        cout << "Case #" << cnt++ << ":" << endl;
        if (tr.prefixExist(s)) {
            ans.clear();
            tr.prefix(s, ans, "");
            for (auto I: ans)cout << I << endl;
        } else {
            cout << "No match." << endl;
        }
    }

}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
    // handle file input
    fileInput();
    init();
    int t = 1;
//    cin >> t;
    int tc = 1;
    while (t--) {
        elmtarshm(tc++);
    }

    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
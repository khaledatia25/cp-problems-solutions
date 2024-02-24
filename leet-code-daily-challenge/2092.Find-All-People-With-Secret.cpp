/*
    --------------------------------------------     ==============
    | Buggy Code Written By Khaled Waleed  ^_^ |     |   For Fun  |
    --------------------------------------------     ==============
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

template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_map =
    tree<T, map<T, F>, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class F>
using ordered_multimap = tree<T, map<T, F>, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_heap = priority_queue<T>;
template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &i : v) os << i << " ";
    os << '\n';
    return os;
}
using ld = long double;

void fileInput(/*Hello World*/);

typedef complex<double> point;

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll mod = 1e9 + 7;
// const ll mod = 998244353;
// const ll mod = 998244353;
const int sz = 1e6;
const int K = +9;
const ll N = 1e6 + 9;
struct dsu {
    map<int, int> par;
    map<int, int> sz;
    map<int, bool> has_secret;
    int find(int x) {
        if (par[x] == x) return x;
        if (!par[x]) return par[x] = x;
        return par[x] = find(par[x]);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        if (sz[u] < sz[v]) swap(u, v);
        has_secret[v] |= has_secret[u];
        has_secret[u] |= has_secret[v];

        par[v] = u;
        return true;
    }
};
class Solution {
    vector<int> par, sz;
    void init(int n) {
        n++;
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        return true;
    }

   public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        int mx_time = 0;
        for (const vector<int> &a : meetings) mx_time = max(mx_time, a[2]);
        vector<int> g[mx_time + 1];
        vector<pair<int, int>> h[mx_time + 1];
        for (const vector<int> &a : meetings) {
            g[a[2]].push_back(a[0]);
            g[a[2]].push_back(a[1]);
            h[a[2]].emplace_back(a[0], a[1]);
        }
        init(n);
        merge(firstPerson, 0);
        for (int i = 1; i <= mx_time; i++) {
            dsu ds;
            for (const int &j : g[i]) {
                if (find(j) == find(firstPerson)) {
                    ds.has_secret[j] = true;
                }
            }
            for (const pair<int, int> &p : h[i]) {
                ds.merge(p.first, p.second);
            }
            for (const int &j : g[i]) {
                if (ds.has_secret[ds.find(j)]) {
                    merge(firstPerson, j);
                }
            }
        }
        int root = find(firstPerson);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (find(i) == root) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// another approach
class Solution2 {
   public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        set<int> knows = {0, firstPerson};
        vector<vector<pair<int, int>>> m;
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        set<int> times;
        for (const vector<int> &meeting : meetings) {
            if (times.find(meeting[2]) == times.end()) {
                times.insert(meeting[2]);
                m.push_back({});
            }
            m.back().push_back({meeting[0], meeting[1]});
        }

        for (const vector<pair<int, int>> &groups : m) {
            set<int> localKnows;
            unordered_map<int, vector<int>> g;

            for (const pair<int, int> &p : groups) {
                g[p.first].push_back(p.second);
                g[p.second].push_back(p.first);

                if (knows.find(p.first) != knows.end()) localKnows.insert(p.first);
                if (knows.find(p.second) != knows.end()) localKnows.insert(p.second);
            }

            queue<int> qu;
            for (const int &p : localKnows) qu.push(p);

            while (!qu.empty()) {
                int cur = qu.front();
                knows.insert(cur);
                qu.pop();
                for (const int next : g[cur]) {
                    if (knows.count(next) == 0) {
                        knows.insert(next);
                        qu.push(next);
                    }
                }
            }
        }
        return vector<int>(knows.begin(), knows.end());
    }
};
void init() {
}

void freePalestine(int tc) {
    Solution sol;
    vector<vector<int>> meetings = {{5, 1, 4},
                                    {0, 4, 18}};
    cout << sol.findAllPeople(11, meetings, 1);
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
        freePalestine(tc++);
    }

    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
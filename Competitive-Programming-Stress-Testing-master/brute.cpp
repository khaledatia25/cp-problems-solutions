/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) v.push_back(i * j);
        }
        sort(v.begin(), v.end());
        int val = v[k - 1];
        cout << val << ' ' << count(v.begin(), v.end(), val) << endl;
    }
    return 0;
}

/*
Input:
5
1 2 3 4 5
2
1 3 2
2 4 1
3
1 4
2 5
3 5

Output:
7
5
2


After the update queries, the array becomes: [3, 0, 1, 6, 5].
The XOR of elements in the given ranges for the queries is as follows:
XOR of elements in the range [1, 4] is 7.
XOR of elements in the range [2, 5] is 5.
XOR of elements in the range [3, 5] is 2.

*/

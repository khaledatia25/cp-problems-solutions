/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
using namespace std;
void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}

string solution(string &text) {
    vector<int> v(26, -1);
    int cur = 9;
    string ans = text;
    for (int i = 0; i < text.size(); i++) {
        if (~v[ans[i] - 'A']) {
            ans[i] = '0' + v[ans[i] - 'A'];
        } else {
            v[ans[i] - 'A'] = cur--;
            ans[i] = v[ans[i] - 'A'] + '0';
        }
    }
    return ans;
}

int32_t main() {
    fileInput();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s = "BABBCDEFGHIJ";
    cout << solution(s) << endl;
    return 0;
}

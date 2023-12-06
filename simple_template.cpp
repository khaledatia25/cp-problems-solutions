/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
using namespace std;
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'
#define ll long long

const int N = 1e6 + 2;

int freq[N], a[N], n, qs[N], qe[N], qi[N], answeres[N], q, sq, s, e, ans;

void add(int val) {
    ans += !freq[val]++;
}

void remove(int val) {
    ans -= !--freq[val];
}

void updateSE(int idx) {
    while (e < qe[idx] + 1) add(a[e++]);
    while (s > qs[idx]) add(a[--s]);
    while (s < qs[idx]) remove(a[s++]);
    while (e > qe[idx] + 1) remove(a[--e]);
}

signed main() {
    // fast input
    KHALED_WALEED_ATTIA
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> qs[i] >> qe[i];
        qs[i]--, qe[i]--;
        qi[i] = i;
    }
    sq = sqrt(n);
    sort(qi, qi + q, [&](int a, int b) {
        return make_pair(qs[a] / sq, qe[a]) < make_pair(qs[b] / sq, qe[b]);
    });
    for (int i = 0; i < q; i++) {
        updateSE(qi[i]);
        answeres[qi[i]] = ans;
    }
    for (int i = 0; i < q; i++) cout << answeres[i] << endl;
    return 0;
}

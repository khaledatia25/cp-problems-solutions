#include <bits/stdc++.h>

#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define endl '\n'
#define eps 1e-9
#define space ' '
using namespace std;

void fileInput();

const int N = 26;
const int M = N * 6 + 9;
long long dp[N][M];
int n, m;

long long dp_jutsu(int i, int sum) {
    if (i == n) {
        return sum >= m;
    }
    long long &ret = dp[i][sum];
    if (~ret)return ret;
    ret = 0;
    for (int j = 1; j <= 6; j++) {
        ret += dp_jutsu(i + 1, sum + j);
    }
    return ret;
}

int32_t main() {
    // fast input
    KHALED_WALEED_ATTIA
    fileInput();
    while (cin >> n >> m, n || m) {
        memset(dp, -1, sizeof dp);
        long long num = dp_jutsu(0, 0);
        long long all = pow(6, n);
        long long g = __gcd(num, all);
        num /= g;
        all /= g;
        if (num == all || num == 0) {
            cout << num << endl;
        } else
            cout << num << "/" << all << endl;
    }
    return 0;
}

void fileInput() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
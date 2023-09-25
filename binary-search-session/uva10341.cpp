#include <bits/stdc++.h>
using namespace std;
void file_input();
double p, q, r, s, t, u;
double f(double x) {
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
signed main() {
  file_input();
  while (cin >> p >> q >> r >> s >> t >> u) {
    double st = 0, nd = 1;
    for (int i = 0; i < 100; i++) {
      double mid = (st + nd) / 2;
      if (f(mid) >= 0) {
        st = mid;
      } else {
        nd = mid;
      }
    }
    double mid = (st + nd) / 2;
    if (fabs(f(mid)) <= 1e-4)
      cout << fixed << setprecision(4) << mid << endl;
    else
      cout << "No solution" << endl;
  }

  return 0;
}

void file_input() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
}
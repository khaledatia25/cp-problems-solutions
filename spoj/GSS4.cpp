/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1 << 17;

struct node {
    bool lessThan2;
    ll sum;
};
node t[N << 1];
ll n;
ll a[N];

node merge(const node &l, const node &r) {
    return {(l.lessThan2 && r.lessThan2), l.sum + r.sum};
}

void build(int ni = 0, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        return void(t[ni] = {a[ns] < 2, a[ns]});
    }
    int left = ni * 2 + 1, right = left + 1, mid = ns + (ne - ns) / 2;
    build(left, ns, mid);
    build(right, mid + 1, ne);
    t[ni] = merge(t[left], t[right]);
}

void update(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    node &cur = t[ni];
    if (qs > ne or qe < ns or cur.lessThan2) return;
    if (ns == ne) {
        cur.sum = (int)sqrtl(cur.sum);
        cur.lessThan2 = (cur.sum < 2);
        return;
    }
    int left = ni * 2 + 1, right = left + 1, mid = ns + (ne - ns) / 2;
    update(qs, qe, left, ns, mid);
    update(qs, qe, right, mid + 1, ne);
    t[ni] = merge(t[left], t[right]);
}

ll query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne or qe < ns) return 0;
    if (ns >= qs and ne <= qe) return t[ni].sum;
    int left = ni * 2 + 1, right = left + 1, mid = ns + (ne - ns) / 2;
    ll L = query(qs, qe, left, ns, mid);
    ll R = query(qs, qe, right, mid + 1, ne);
    return L + R;
}

int32_t main() {
    int cses = 1;
    while (~scanf("%lld", &n)) {
        printf("Case #%d:\n", cses);
        cses++;

        for (int j = 0; j < n; ++j) {
            scanf("%lld", a + j);
        }
        build();

        int q;
        scanf("%d", &q);
        for (int _ = 1; _ <= q; ++_) {
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);

            if (r < l) {
                swap(l, r);
            }

            if (t == 0) {
                update(--l, --r);
            } else {
                printf("%lld\n", query(--l, --r));
            }
        }
        puts("");
    }

    return 0;
}

/*
    Buggy Code Written By Khaled Waleed  ^_^
*/
#include <bits/stdc++.h>
#define KHALED_WALEED_ATTIA ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define space " "
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define ll long long
#define int long long
#define OO (ll)1e18
#define oo (ll)1e9

/*
    Geometry Staff
*/

#define X real()
#define Y imag()

#define angle(a) (atan2((a).imag(), (a).real()))

#define vec(a, b) ((b) - (a))

#define dp(a, b) ((conj(a) * (b)).real()) // a*b cos(T), if zero -> prep

#define cp(a, b) ((conj(a) * (b)).imag()) // a*b sin(T), if zero -> parllel

using namespace std;
typedef complex<double> point;
void fileInput();

int dx[] = {-1, 0, 1, 0},
    dy[] = {0, 1, 0, -1};

const ll mod = 1e9 + 7;
const int sz = 2e5 + 9;

const ll N = 1e7 + 9;

double EPS = 1.0 / 1e9;

int ccw(point a, point b, point c)
{
    point v1(b - a), v2(c - a);
    double t = cp(v1, v2);

    if (t > +EPS)
    {
        return +1;
    }
    if (t < -EPS)
    {
        return -1;
    }
    if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
    {
        return -1;
    }
    if (norm(v1) < norm(v2) - EPS)
    {
        return +1;
    }
    return 0;
}

bool intersect(point p1, point p2, point p3, point p4)
{
    bool x = (p1 == p2), y = (p3 == p4);
    if (x && y)
        return p1 == p3;
    if (x)
        return ccw(p3, p4, p1) == 0;
    if (y)
        return ccw(p1, p2, p3) == 0;
    return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

int32_t main()
{
    // fast input
    KHALED_WALEED_ATTIA

    // handle file input
    fileInput();

    // solution function
    int m, n, x, y;

    function<void(int)> sol;
    sol = [&](int test) -> void
    {
        int n;
        cin >> n;
        vector<array<point, 2>> v(n);
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v[i][0] = point(x, y);
            cin >> x >> y;
            v[i][1] = point(x, y);
        }
        // Build Graph
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (intersect(v[i][0], v[i][1], v[j][0], v[j][1]))
                {
                    graph[i][j] = 1;
                }
            }
        }

        // Floyed
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                }
            }
        }

        int a, b;
        while (cin >> a >> b, a && b)
        {
            a--, b--;
            if (graph[a][b])
                cout << "CONNECTED" << endl;
            else
                cout << "NOT CONNECTED" << endl;
        }
    };

    // tests
    int t = 1;
    cin >> t;

    // looooop
    int test = 1;
    while (t--)
    {
        if (test > 1)
            cout << endl;
        sol(test++);
    }

    return 0;
}

void fileInput()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
}
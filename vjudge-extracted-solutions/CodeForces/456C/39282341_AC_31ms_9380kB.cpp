#include <bits/stdc++.h>
#define pb(x) push_back(x);
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define fore(i,e) for(ll i = 0; i < e; i++)
#define ll long long

const ll mod=1e9+7;
const ll sz=1e6+7;
using namespace std;

ll n;
ll a[100009];
ll mem[100009];
ll dp(ll index)
{
if (index>=1e5+1) return 0;


ll &ret=mem[index];

if (ret!=-1) return ret;

ret=0;

ret=max(
a[index]+dp(index+2),
dp(index+1)
);

return ret;


}

int main()
{
    fast_cin();


    cin >>n;
    for(int i=0;i<n;i++)
    {
    int x;
    cin >>x;
    a[x]++;
    }

    for(int i=0;i<100009;i++) a[i]=i*a[i];

    memset(mem,-1,sizeof mem);

    cout << dp(0);

    return 0;
}
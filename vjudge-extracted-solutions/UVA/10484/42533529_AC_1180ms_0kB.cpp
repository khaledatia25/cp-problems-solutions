/*Mohamed Ahmed Nabil

   Prime Factorize the factorial  using each of the 1-N numbers

   Then take away the numbers needed to make it divisible by D.. The factors that we always must have

   Then we will be left with a collection of factors 
   Calculate how many way to select from them... Product of the count of each +1

   
*/
#include <bits/stdc++.h>
#include <complex>
using namespace std;

#define lp(i,n) for(int i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long ,long long>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-6
#define OO 1000000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<int> point;
#define X real()
#define Y imag()

#define vec(a,b) (b-a)
#define angle(a) (atan2(((a).Y),((a).X)))

#define length(a) (hypot(((a).real()),((a).imag())))
#define normalize(a) ((a)/(length(a)))

#define dotp(a,b) ((conj(a)*(b)).real())
#define crossp(a,b) ((conj(a)*b).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;
const double PI= acos(-1.0);
double fixAngle(double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp(double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

ll cnt[200];

void mark(ll a){
    ll temp=a;
    for(ll i=2; i*i<=a; i++){


        while(temp%i==0){
                cnt[i]++;
                temp/=i;
        }




    }

    if(temp!=1){
       cnt[temp]++;
    }


}

int main(){
//debugme;

    ll d,n;
  while(1){
        memset(cnt,0,sizeof cnt);
    cin>>n>>d;
    if(!n && !d) return 0;
    vector<pii> pf_d;

    ll temp=d;
    for(int i=2; i*i<=d; i++){
        if(temp%i==0){
            int c=0;
            while(temp%i==0){
                c++;
                temp/=i;
            }
            pf_d.pb(pii(i,c));

        }

    }

    if(temp!=1){
        pf_d.pb(pii{temp,1});
    }

    for(int i=2; i<=n; i++){
        mark(i);
    }

    ll ans=1;
    for(auto x:pf_d){
        if(x.ff>150){
            ans=0;
            break;
        }
        if(cnt[x.ff]<x.ss){
            ans=0;
            break;
        }
        cnt[x.ff]-=x.ss;
    }

    for(ll i=0; i<=150; i++){
        ans*=cnt[i]+(ll)1;
    }
    cout<<ans<<endl;

  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
#define FORW(i,a,b) for(int i=a;i<=b;i++)
#define FORB(i,a,b) for (int i=a;i>=b;i--)
#define forw(i,a,b) for (ll i=a;i<=b;i++)
#define forb(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fr front
#define all(a) a.begin(),a.end()
#define endl "\n"
#define db(val) "["#val" = "<<(val)<<"] "
int dX[] ={0,-1,0,1};
int dY[]= {-1,0,1,0};
const ll oo=1e18;
const ll MOD=1e9+7;
const ll mod=1e9+9;
const int mxN=2e5+7;
ll p1[mxN],p2[mxN],a[mxN];
int n;
ll d;
ll res=0;
int main()
{
    fast;
    freopen("test.INP","r",stdin);
    freopen("test.OUT","w",stdout);
    cin>>n>>d;
    FORW(i,1,n){
        int t;
        cin>>a[i];
        if (!(i%2))
         p1[i]=p1[i-2]+(a[i-1]*a[i]);
        else
         p1[i]=p1[i-1]+a[i];
    }
    FORW(i,2,n){
        if ((i%2))
            p2[i]=p2[i-2]+(a[i-1]*a[i]);
       else
         p2[i]=p2[i-1]+a[i];
    }

   map<ll,ll> save1,save2 ;
    FORW(i,1,n){
        auto pos = lower_bound(p1+1,p1+i+1,p1[i]-d)-(p1+1);
        res+=i-pos;
        if (pos%2) res--;
        cout<<pos<<endl;
    }
    FORW(i,2,n){
        auto pos = lower_bound(p2+2,p2+i+2,p2[i]-d)-(p2+2);
        res+=i-pos;
        if (pos%2) res--;
        cout<<pos<<endl;
    }
    FORW(i,2,n){
            save2[p1[i]]=i;
            save1[p2[i]]=i;
            res+=i-save1[p2[i]-d];
            res+=i-save2[p1[i]-d];
    }
    for (auto v: save1)
         cout<<v.fi<<": "<<v.se<<endl;

    cout<<(1LL*(ll)round(res/2.0));

}


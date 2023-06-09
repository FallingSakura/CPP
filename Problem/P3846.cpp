#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p,b,n;
ll ksm(ll a,ll b,ll p)
{
    if(b==0) return 1;
    ll z=ksm(a,b/2,p);
    z=z*z%p;//有sb写快速幂不%p
    if(b%2==1) z=z*a%p;
    return z;
}
signed main()
{
    scanf("%lld%lld%lld",&p,&b,&n);
    //b^x=n(mod p)
    ll s=1ll*sqrt((1.0*p));
    // cout<<s<<endl;
    set<int> se;
    for(int i=0;i<s;i++)
    {
        ll a=ksm(b,i,p);
        se.insert(a);
    }
    ll ans=-1;
    for(ll i=0;i*s<=p;i++)
    {
        ll x=n*ksm(ksm(b,i*s,p),p-2,p)%p;
        if(se.count(x)!=0)
        {
            ll v=ksm(b,i*s,p);
            for(ll j=i*s;;j++)
            {
                if(v==n)
                {
                    ans=j;
                    break;
                }
                v=v*b%p;
            }
            break;
        }
    }
    if(ans!=-1) printf("%lld",ans);
    else printf("no solution");
    return 0;
}
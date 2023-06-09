#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ll n=0,k=0,x=0,y=0;
        scanf("%lld%lld",&n,&k);
        if(k<n-k)
        {
            printf("%lld %lld\n",k,n-k);
            continue;
        }
        if(y==0) printf("-1\n");
        else printf("%lld %lld\n",x,y);
    }
    return 0;
}
        // for(ll p=1;p<=n-k;p*=(1000000+7))
        // {
        //     ll check=(n-k)%(p+1);
        //     if(check==0)
        //     {
        //         y=(n-k)/(p+1);
        //         x=n-y;
        //         if(x<0||x>n||k>y)
        //         {
        //             x=y=0;
        //             continue;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        // }
        // if(n<k)
        // {
        //     printf("-1");
        //     return 0;
        // }
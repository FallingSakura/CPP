#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,p;
int x[1255],y[1255];
int fac[200025],ifac[200025];
int c(int x,int y)
{
    if(x<y) return 0;
    return fac[x]*ifac[y]*ifac[x-y]%p;
}
int ksm(int x,int y)
{
    if(y==0) return 1;// c(n,m)恰好为p的倍数，导致x小于y，访问到负下标
    int z=ksm(x,y/2);
    z=z*z%p;
    if(y%2==1) z=z*x%p;
    return z;
}
void pre()
{
    memset(fac,0,sizeof(fac));
    memset(ifac,0,sizeof(ifac));
    fac[0]=1;
    ifac[0]=1;
    for(int i=1;i<=200002;i++)
    {
        fac[i]=fac[i-1]*i%p;
        ifac[i]=ksm(fac[i],p-2)%p;
    }
    return;
}
long long lucas(int n,int m)
{
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    while(n)
    {
        x[0]++;
        x[x[0]]=n%p;
        n=n/p;
    }
    while(m)
    {
        y[0]++;
        y[y[0]]=m%p;
        m=m/p;
    }
    int ans=1;
    for(int i=1;i<=x[0];i++)
    {
        ans=ans*c(x[i],y[i])%p;
    }
    return ans;
}
signed main()
{
    scanf("%lld",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld",&n,&m,&p);
        pre();
        printf("%lld",lucas(n+m,n)%p);
        if(i!=t) puts("");
    }
    return 0;
}
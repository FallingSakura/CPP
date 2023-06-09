#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
inline ll read()
{
	ll x=0,y=1;//x是什么，y是正负 
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
void solve(ll a,ll b,ll c,ll d,ll &p,ll &t)
{
    if(a<c)
    {
        swap(a,c);
        swap(b,d);
    }
    ll x=b;
    ll g=gcd(a,c);
    ll l=a/g*c;
    while(x%c!=d&&x<=l)
    {
        x+=a;
    }
    if(x>l) p=-1,a=-1;
    else p=l,t=x;
}
signed main()
{
    scanf("%d",&n);
    ll a,b,p,t;
    p=read();
    t=read();
    t%=p;
    for(int i=2;i<=n;i++)
    {
        a=read();
        b=read();
        b%=a;//防止模数比被模数还大
        solve(a,b,p,t,p,t);
    }
    printf("%lld",t);
}
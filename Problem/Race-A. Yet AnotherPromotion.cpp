#include<bits/stdc++.h>
using namespace std;
long long a,b,n,m,ans;
long long c1,c2,c3=1e9;
signed main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%lld%lld",&a,&b);//第一天a元每斤，第二天b元每斤
        scanf("%lld%lld",&n,&m);//要买n斤，但是买m斤送一斤（仅在第一天生效）
        c1=n/(m+1)*a*m+(n-(n/(m+1)*(m+1)))*a;
        c2=n*b;
        c3=n/(m+1)*a*m+(n-(n/(m+1)*(m+1)))*b;
        ans=min(min(c1,c2),c3);
        printf("%lld\n",ans);
    }
}
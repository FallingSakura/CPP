#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long sum,n,a[maxn],b[maxn];
signed main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%lld",&n);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld%lld",&a[j],&b[j]);
            sum+=abs(b[j]-a[j]);
        }
        sum%=2;
        printf("%lld\n",sum);
        sum=0;
    }
    return 0;
}
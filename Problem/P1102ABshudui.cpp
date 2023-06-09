#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200100];
signed main()
{
    int n,c;
    scanf("%lld%lld",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        tot+=upper_bound(a+1,a+n+1,a[i]+c)-lower_bound(a+1,a+n+1,a[i]+c);
    }
    printf("%lld",tot);
}
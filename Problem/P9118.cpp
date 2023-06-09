#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int num[100];
signed main()
{
    scanf("%lld%lld",&n,&k);
    for(int a=k;a<=65;a++)
    {
        // long long v=pow(n,1.0/a)-1;//精度
        long long v=(long long)floor(exp(log(n)/a))-1;
        int d=1-num[a];
        ans+=v*d;
        for(int b=a;b<=65;b+=a)
        {
            num[b]+=d;
        }
    }
    ans++;
    printf("%lld",ans);
    return 0;
}
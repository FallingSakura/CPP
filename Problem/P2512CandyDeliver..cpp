#include<bits/stdc++.h>
using namespace std;
long long a[1000005],c[1000005],n,cnt=0;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        cnt+=a[i];
    }
    long long ave=cnt/n;
    for(int i=1;i<=n;i++)
        c[i]=c[i-1]-ave+a[i-1];
    sort(c+1,c+n+1);
    long long mid=c[(n+1)/2],sum=0;
    for(int i=1;i<=n;i++)
        sum+=abs(mid-c[i]);
    printf("%lld",sum);
}
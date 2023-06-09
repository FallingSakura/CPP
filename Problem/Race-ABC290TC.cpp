#include<bits/stdc++.h>
using namespace std;
int a[300005];
signed main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int in=unique(a,a+n)-a;
    for(int i=0;i<=k;i++)
    {
        if(a[i]!=i)
        {
            printf("%d",i);
            return 0;
        }
    }
    
    if(k<=in)
        printf("%d",a[k]);
    else
        printf("%d",a[in]);
    return 0;
}
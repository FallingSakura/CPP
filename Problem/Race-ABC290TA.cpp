#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000];
signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        ans+=a[b[i]];
    }
    printf("%d",ans);
    
}
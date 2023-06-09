#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9;
int a[1000010],n,c;
bool P(int d)
{
    int k=0,last=-maxn;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-last>=d)
        {
            last=a[i];
            k++;
        }
    }
    return k>=c;
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=0,r=1e9,ans,mid;
    while(l<=r)
    {
        if(P(mid=l + r >> 1))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    printf("%d",ans);
}
#include<bits/stdc++.h>
using namespace std;
int a[1001000],q;
int n,m;
int find(int x)
{
    // int l=1,r=n;
    // while(l<=r)
    // {
    //     int mid=(l+r)>>1;
    //     if(a[mid]==x)
    //         return mid;
    //     else if(a[mid]>x) r=mid-1;
    //     else l=mid+1;
    // }
    // return -1;
    int l=1,r=n+1;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(a[mid]>=x) r=mid;
        else l=mid+1;
    }
    if(a[l]==x) return l;
    else return -1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&q);
        printf("%d ", find(q) );
    }
    return 0;
}
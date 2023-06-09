#include<bits/stdc++.h>
using namespace std;
int n,lis,maxn;
int f[100005],a[100005];
int lowbit(int x)
{
    return x & -x;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res=max(res,f[i]);
    return res;
}
void add(int x,int c)
{
    for(int i=x;i<=maxn;i+=lowbit(i))
        f[i]=max(f[i],c);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int q=query(a[i]-1);
        add(a[i],q+1);
        lis=max(lis,q+1);
    }
    printf("%d",lis);
    return 0;
}
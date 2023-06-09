#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+6;
int ans=maxn;
struct node{
    int l,r,v,fa;
}t[maxn];
bool vis[maxn];
int dfs(int x,int d)
{
    if(!x||vis[x]) return  0;
    vis[x]=1;
    return dfs(t[x].l,d+1)+dfs(t[x].r,d+1)+dfs(t[x].fa,d+1)+t[x].v*d;
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&t[i].v,&t[i].l,&t[i].r);
    for(int i=1;i<=n;i++)
    {
        t[t[i].l].fa=i;
        t[t[i].r].fa=i;
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans=min(ans,dfs(i,0));
    }
    printf("%d",ans);
}
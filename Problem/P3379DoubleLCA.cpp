#include<bits/stdc++.h>
using namespace std;
#define maxn 1000007
int dist[maxn],first[maxn],f[maxn][20],depth[maxn],g[maxn][20];
int n,m,s;
struct edge
{
    int e,next;
    int d;//长度
}ed[maxn];
int cnt;
void add_edge(int u,int v,int w=0)
{
    cnt++;
    ed[cnt].next=first[u];
    ed[cnt].e=v;
    ed[cnt].d=w;
    first[u]=cnt;
}
void dfs(int now)//从根节点开始dfs//预处理
{
    for(int i=first[now];i;i=ed[i].next)
        if(ed[i].e!=f[now][0])
        {
            int p=ed[i].e;
            depth[p]=depth[now]+1;
            f[p][0]=now;
            for(int x=1;x<=18;x++)
            {
                f[p][x]=f[f[p][x-1]][x-1];
            }
            dfs(p);
        }
}
//1.调整深度2.一起跳
int get_lca(int p1,int p2)//魔改后是求边权最小值
{
    if(depth[p1]<depth[p2]) swap(p1,p2);//保证p1较深
    for(int x=18;x>=0;x--)
    {
        int p=f[p1][x];
        if(depth[p]>=depth[p2])
        {
            p1=p;//完成后p1p2深度就一致了
        }
    }
    if(p1==p2) return p1;//防止p1，p2在同一点上
    for(int x=18;x>=0;x--)
    {
        if(f[p1][x]!=f[p2][x])
        {
            p1=f[p1][x],p2=f[p2][x];
        }
    }
    return f[p1][0];
}
int main()
{
    depth[0] = -1;//防止跳到０号点，因为０号点的深度默认为０，和根节点的深度一样；
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(s);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",get_lca(a,b));
    }
}
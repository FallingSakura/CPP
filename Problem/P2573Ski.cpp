#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;//有双向边于是要开两倍数组
int n,m;
int h[maxn];
struct edge{
    int next,to,k,from;
}e[maxn];
struct edge2{
    int u,v,w;
}e2[maxn];
int fa[maxn];
int first [maxn];
bool bj[maxn];
int cn,cn2;
int cnt;
long long ans;
int q[maxn],l,r;
void add_edge(int u,int v,int w)
{
    e[++cn].next=first[u];
    e[cn].to=v;
    e[cn].k=w;
    first[u]=cn;
} 
bool cmp(edge2 a,edge2 b)
{
    if(h[a.v]!=h[b.v]) return h[a.v]>h[b.v];
    return a.w<b.w;
}
int find(int x)
{
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
void dfs(int now)
{
    bj[now]=1;
    cnt++;//可以走的路径的条数
    for(int i=first[now];i;i=e[i].next)
    {
        e2[++cn2].u=now;
        e2[cn2].v=e[i].to;
        e2[cn2].w=e[i].k;
        if(!bj[e[i].to])
        {
            dfs(e[i].to);
        }
    }
}
void Kruscal()
{
    sort(e2+1,e2+cn2+1,cmp);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=cn2;i++)
    {
        int rootu=find(e2[i].u);
        int rootv=find(e2[i].v);
        if(rootu!=rootv)
        {
            ans+=e2[i].w;
            fa[rootu]=rootv;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(h[a]==h[b])
        {
            add_edge(a,b,c);
            add_edge(b,a,c);
        }
        else if(h[a]<h[b]) add_edge(b,a,c);
        else add_edge(a,b,c);
        
    }
    dfs(1);
    printf("%d ",cnt);
    Kruscal();
    printf("%lld",ans);
}
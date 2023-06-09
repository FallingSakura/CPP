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
void add_edge(int u,int v,int w)
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
            g[p][0]=ed[i].d;//代表从p向上走……步（这里指一步）所经过的最短距离为这条边的边权
            for(int x=1;x<=18;x++)
            {
                f[p][x]=f[f[p][x-1]][x-1];
                g[p][x]=min(g[p][x-1],g[f[p][x-1]][x-1]);
            }
            dfs(p);
        }
}
//1.调整深度2.一起跳
int get_lca(int p1,int p2)//魔改后是求边权最小值
{
    if(depth[p1]<depth[p2]) swap(p1,p2);//保证p1较深
    int ans=INT_MAX;
    for(int x=18;x>=0;x--)
    {
        int p=f[p1][x];
        if(depth[p]>=depth[p2])
        {
            ans=min(ans,g[p1][x]);
            p1=p;//完成后p1p2深度就一致了
        }
    }
    if(p1==p2) return p1;//防止p1，p2在同一点上
    for(int x=18;x>=0;x--)
    {
        if(f[p1][x]!=f[p2][x])
        {
            ans=min(ans,min(g[p1][x],g[p2][x]));
            p1=f[p1][x],p2=f[p2][x];
        }
    }
    return min(ans,min(g[p1][0],g[p2][0]));//再向上跳一个
}
int main()
{
    depth[0]=-1;//初始化0号点，防止跳到0号点
}
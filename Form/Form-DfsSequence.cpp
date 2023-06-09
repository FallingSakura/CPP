#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int q[maxn],l[maxn],r[maxn];
// l[1]=1,r[1]=n;//一号点（假设1是根节点）在序列中左端点是1，右端点是n
// void dfs(int now,int f)//dfs序//会爆栈
// {
//     q[l[now]]=now;//q就是dfs序列
//     int x=l[now]+1;//下一个儿子对应的左端点
//     size[now]=1;
//     for(int i=first[now];i;i=ed[i].next)
//     {
//         if(ed[i]!=f)
//         {
//             l[ed[i].e]=x;
//             dfs(ed[i].e,now);
//             x=r[ed[i].e]+1;//下一个儿子的左端点=上一个儿子右端点+1
//             size[now]+=size[ed[i].e];//求出所有点的size
//         }
//     }
//     r[now]=l[now]+size[now]-1;
// }
//---
bool vis[maxn];
void bfs()//bfs求dfs序//避免爆栈
{
    int front=1,tail=1;
    q[1]=1;
    vis[1]=1;
    for(;front<=tail;)
    {
        int now=q[front++];
        for(int i=first[now];i;i=ed[i].next)
        {
            if(!vis[ed[i].e])
            {
                q[++tail]=ed[i].e;
                vis[ed[i].e]=true;
            }
        }
    }
    for(int i=n;i>=1;i--)//从叶子往根枚举//求出所有的size
    {
        int now=q[i];
        size[now]=1;
        for(int i=first[now];i;i=ed[i].next)
        {
            if(size[ed[i].e])
                size[now]+=size[ed[i].e];
        }
    }
    l[1]=1,r[1]=n;
    for(int i=1;i<=n;i++)//处理序列
    {
        int now=q[i];
        int x=l[now]+1;
        for(int i=first[now];i;i=ed[i].next)
        {
            if(size[ed[i].e]<size[now])//size比now小说明是now的一个儿子
            {
                l[ed[i].e]=x;//第一个儿子的序号等于我的序号+1
                r[ed[i].e]=l[ed[i].e]+size[ed[i].e]-1;//右端点=左端点＋size-1
                x=r[ed[i].e]+1;//同上
            }
        }
    }
    for(int i=1;i<=n;i++)
        q[l[i]]=i;
}
int n,m;
int main()
{
    scanf("%d%d",&n,&m);

}
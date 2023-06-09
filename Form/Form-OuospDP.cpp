#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int vis[maxn],fa[maxn],circle[maxn],first[maxn],cnt;
bool in_circle[maxn];
struct node
{
    int next,e;
}ed[maxn];
bool dfs_circle(int now)//bool表示有没有找到环，防止再找
{
    vis[now]=true;
    for(int p=first[now];p;p=ed[p].next)
    {
        if(vis[ed[p].e])//如果下一个点已经被走过了
        {
            if(ed[p].e==fa[now]) continue;
            if(ed[p].e==now) continue;//防止自环
            int x=now;
            while(x!=ed[p].e)//找环
            {
                cnt++;
                circle[cnt]=x;
                in_circle[x]=true;
                x=fa[x];
            }
            //ed[p].e这个点也要加进环里
            cnt++;//环上点的数量
            circle[cnt]=x;
            in_circle[x]=true;
            x=fa[x];
            return true;
        }
        else
        {
            fa[ed[p].e]=now;//记录父亲
            if(dfs_circle(ed[p].e)) return true;
        }
    }
    return false;
}
void dfs_dp(int now)
{
    for(int p=first[now];p;p=ed[p].next)
    {
        if(!in_circle[ed[p].e])
        {
            //转移方程
        }
    }
}

int main()
{
    for(int i=1;i<=cnt;i++)
        dfs_dp(circle[i]);//树形dp，做完再做环形DP
}
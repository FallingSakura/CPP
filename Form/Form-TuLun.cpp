#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int e,next;//终点//下一条边的编号
}ed[maxm];//maxm最多边数、maxn最多点数
int en,first[maxn];//first[i]指从i出发的第一条边的编号
int en=0;
void add_edge(int s,int e)//s-->e
{
    en++;//边的数量+1
    ed[en].next=first[s];//把en这条边放在上一条边之前
    first[s]=en;//以s为起点的第一条边编号就是en啦
    ed[en].e=e;//终点赋值
}
//
//枚举
for(int p=first[1];p!=0;p=ed[p].next)
    ed[p].e;
//没有上司的舞会---章鱼图
bool dfs_circle(int now)//找环
{
    vis[now]=true;
    for(int p=first[now];p!=0;p=ed[p].next)
    {
        if(vis[ed[p].e])//是否被访问过
        {
            if(ed[p].e==f[now]) continue;
            int x=now;
            while(x!=ed[p].e)//找环
            {
                cnt++;//多了个点
                circle[cnt]=x;//这个点是x
                in_circle[x]=true;//标记
                x=f[x];//向上跳
            }
            //把ed[p].e也放进去 
            cnt++;
            circle[cnt]=x;
            in_circle[x]=true;
            x=f[x];
            return true;
        }
        else{
            f[ed[p].e]=now//终点的父亲是自己
            if (dfs_circle(ed[p].e)) return true;
        }
        return false;
    }
}
void dfs_dp(int now)
{
    for(int p=first[now];p!=0;p=ed[p].next)
    {
        if(!in_circle[ed[p].e])//不在环上
        {
            //转移方程
        }
    }
}
for(int i=1;i<=cnt;i++)
{
    dfs_dp(circle[i]);//对环上每个点树形dp
    //再环形dp
}
//———————————分割线————————————————————————————————————————————————————————

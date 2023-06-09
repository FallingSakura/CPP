#include<bits/stdc++.h>
using namespace std;
#define maxn 1000007
int first[maxn],dist[maxn];
bool inque[maxn];
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
void spfa(int s)
{
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    queue<int> q;
    q.push(s);//一开始只知道s的最短路
    while(q.size())
    {
        int now=q.front();
        q.pop();
        inque[now]=false;//记录当前点在不在队列里
        for(int i=first[now];i;i=ed[i].next)
        {
            int e=ed[i].e;
            int d=dist[now]+ed[i].d;
            if(d<dist[e])
            {
                dist[e]=d;//如果e变短了，那么也可以用它去更新其他点的最短路
                if(!inque[e])
                {
                    inque[e]=true;
                    q.push(e);
                }
            }
        }
    }
}
int main()
{
    return 0;
}
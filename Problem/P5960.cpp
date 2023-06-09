#include<bits/stdc++.h>
using namespace std;
const int maxn=60000;
int first[maxn],dist[maxn];
bool inque[maxn];
struct edge
{
    int e,next;
    int d;//长度
}ed[maxn];
int cnt;
int n,m;
void add_edge(int u,int v,int w)
{
    cnt++;
    ed[cnt].next=first[u];
    ed[cnt].e=v;
    ed[cnt].d=w;
    first[u]=cnt;
}
int times[60000];
bool spfa(int s)
{
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    inque[s]=true;
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
                    times[e]++;
                    if(times[e]>n+1)//因为有0号点
                        return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        add_edge(0,i,0);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add_edge(b,a,c);
    }
    if(spfa(0))
        cout<<"NO"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
            printf("%d ",dist[i]);
    }
    return 0;
}
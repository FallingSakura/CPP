#include<bits/stdc++.h>
using namespace std;
#define maxn 1000007
int first[maxn],dist[maxn],times[maxn];
bool inque[maxn];
struct edge
{
    int e,next;
    int d;//长度
}ed[maxn];
int cnt;
int T,n,m;
void add_edge(int u,int v,int w)
{
    cnt++;
    ed[cnt].next=first[u];
    ed[cnt].e=v;
    ed[cnt].d=w;
    first[u]=cnt;
}
bool spfa(int s)
{
    memset(times,0,sizeof(times));
    memset(inque,0,sizeof(inque));
    memset(dist,0x3f,sizeof(dist));
    times[s]=1;
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
                    times[e]++;//记录入队次数
                    if(times[e]>n)//因为有0号点
                        return true;//存在负环
                }
            }
        }
    }
    return false;
}
int main()
{
    
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d",&n,&m);
        for(int j=1;j<=m;j++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c>=0)
            {
                add_edge(a,b,c);
                add_edge(b,a,c);
            }
            else add_edge(a,b,c);
            
        }
        if(spfa(1))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        memset(first,0,sizeof(first));
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int fir[N],dist[N],cnt,n,m,t[N],Q,righ[N];
int x,y,day;
int bj[N];
struct edge{
    int to,next,w;
}e[N];
struct point{
    int p,d;
    point(){}
    point(int a,int b){p=a;d=b;}
};
void add(int u,int v,int w)
{
    e[cnt++].next=fir[u];
    e[cnt].to=v;
    e[cnt].w=w;
    fir[u]=cnt;
}
bool operator<(const point &a,const point &b)
{
    return a.d>b.d;
}
priority_queue<point>q;
void dijkstra(int s)
{
    while(!q.empty())
        q.pop();
    memset(righ,0,sizeof(righ));
    memset(bj,-1,sizeof(bj));
    for(int i=0;i<n;i++)
    {
        if(t[i]<=day)
            bj[i]=1;
    }
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    q.push(point(s,0));
    for(int i=0;i<n;i++)
    {
        if(i==s) continue;
        q.push(point(i,dist[i]));
    }
        
    for(int i=0;i<n;i++)
    {
        while(righ[q.top().p])
            q.pop();
        point now=q.top();
        q.pop();
        int p=now.p;
        if(!bj[p]) continue;
        righ[p]=1;
        for(int j=fir[p];j;j=e[j].next)
        {
            int v=e[j].to;
            if(bj[v]==-1) continue;
            int dd=dist[p]+e[j].w;
            if(dist[v]>dd)
            {
                dist[v]=dd;
                q.push(point(v,dd));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        scanf("%d%d%d",&x,&y,&day);
        if(t[x]>day||t[y]>day)
        {
            printf("-1\n");
            continue;
        }
        dijkstra(x);
        if(dist[y]!=1061109567) printf("%d\n",dist[y]);
        else printf("-1\n");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int F,P,C,M;
int fir[N],cnt,dist[N],righ[N],a[N],l[N];
struct edge{
    int to,next,w;
}e[N];
struct point{
    int p,d;
    point(){}
    point(int a,int b){p=a;d=b;}
};
bool operator<(const point &a,const point &b)//小根堆
{
    return a.d>b.d;
}
priority_queue<point>q;
void add(int u,int v,int w)
{
    e[++cnt].next=fir[u];
    e[cnt].to=v;
    e[cnt].w=w;
    fir[u]=cnt;
}
void dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    for(int i=1;i<=F;i++)
        q.push(point(i,dist[i]));
    for(int i=1;i<=F;i++)
    {
        while(righ[q.top().p])
            q.pop();
        point now=q.top();
        int p=now.p;
        righ[p]=1;
        q.pop();
        for(int j=fir[p];j;j=e[j].next)
        {
            int v=e[j].to;
            int d=dist[p]+e[j].w;
            if(d<dist[v])
            {
                dist[v]=d;
                q.push(point(v,d));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&F,&P,&C,&M);
    for(int i=1;i<=P;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dijkstra();
    for(int i=1;i<=C;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=C;i++)
    {
        if(dist[a[i]]<=M)
            l[++ans]=i;
    }
    sort(l+1,l+ans+1);
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
        cout<<l[i]<<endl;
    return 0;
}
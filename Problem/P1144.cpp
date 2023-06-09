#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int mod=100003;
int n,m;
int dist[N];
struct edge{
    int next,to,w;
}e[N];
int fir[N],cnt,ans[N],righ[N];
struct point{
    int p,d;//到p的最短距离是d
    point(){}
    point(int a,int b){p=a;d=b;}
};
priority_queue<point> q;
void add(int u,int v)
{
    e[++cnt].next=fir[u];
    e[cnt].to=v;
    e[cnt].w=1;
    fir[u]=cnt;
}
bool operator<(const point &a,const point &b)//STL默认大根堆，上面是大的
{
    return a.d>b.d;
}
void dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    ans[1]=1;
    for(int i=1;i<=n;i++)
        q.push(point(i,dist[i]));
    for(int i=1;i<=n;i++)
    {
        while(righ[q.top().p])
            q.pop();
        point now=q.top();
        q.pop();
        int p=now.p;
        righ[p]=1;
        for(int j=fir[p];j;j=e[j].next)
        {
            int ee=e[j].to;
            int dd=dist[p]+e[j].w;
            if(dist[ee]>dd)
            {
                dist[ee]=dd;
                ans[ee]=ans[p];
                q.push(point(ee,dd));
            }
            else if(dist[ee]==dd)
                ans[ee]=(ans[ee]+ans[p])%mod;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {  
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    puts("");
    return 0;
}
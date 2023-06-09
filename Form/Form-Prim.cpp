#include<bits/stdc++.h>
using namespace std;
#define maxn 1000007
int dist[maxn],first[maxn];
int n,m,s;
bool righ[maxn];//这个点有没有放到右边去
struct point{
    int p,d;//原点到p的最短距离为d
    point(){}
    point(int a,int b){p=a;d=b;}
};
bool operator<(const point &a,const point &b)//STL默认大根堆，上面是大的
{
    return a.d>b.d;
}
priority_queue<point> heap;
//松弛操作
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
void prim(int s)
{
    memset(dist,0x3f,sizeof(dist));//全部都赋值为最大值
    dist[s]=0;//s到s
    for(int i=1;i<=n;i++)
        heap.push(point(i,dist[i]));//可以无变量名
    for(int i=1;i<=n;i++)
    {
        while(righ[heap.top().p])//有些点被拿到了右边但是左边没有删除
            heap.pop();
        point now=heap.top();
        heap.pop();
        int p=now.p;
        // int p=-1;//代表还没选任何点
        // for(int j=1;j<=n;j++)//循环后就找到了在左边最短路最小的点
        // {
        //     if(!righ[j]&&(p==-1||dist[p]>dist[j]))//righ[]代表有没有放到右边去
        //         p=j;
        // }
        righ[p]=1;//放到右边
        for(int j=first[p];j; j=ed[j].next)//ed[j].e即为p的下一个点
        {
            int e=ed[j].e;
            int d=ed[j].d;
            if(dist[e]>d)
            {
                dist[e]=d;
                heap.push(point(e,d));//改不了那就丢一个新元素进去
            }
            // dist[ed[j].e]= min(dist[ed[j].e],ed[j].d);
        }
    }
}
signed main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==1061109567)
        {
            cout<<2147483647<<" ";
            continue;
        }
        printf("%d ",dist[i]);
    }
        
    return 0;
}
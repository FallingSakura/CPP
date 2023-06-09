#include<cstring>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
// int d[10001][11],head[10001],q[100001][2];
int head[110001];
int dist[110001];
bool vis[110001];
int n,m,k,cnt,st,ed;
struct data{int to,next,v;}e[2500001];
void ins(int u,int v,int w=0)
{e[++cnt].to=v;e[cnt].v=w;e[cnt].next=head[u];head[u]=cnt;}
inline int Read()
{
    int x=0;char c=getchar();
    while(!isdigit(c))
    {
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c^48);
        c=getchar();
    }
    return x;
}
//这道题spfa会被卡，所以得用dijkstra
/*void spfa()
{
	int t=0,w=1;
	memset(d,127/3,sizeof(d));
	q[0][0]=st;q[0][1]=0;
	inq[st][0]=1;d[st][0]=0;
	while(t!=w)
	{
		int now=q[t][0],tmp=q[t++][1];
		if(t==100001)t=0;
		for(int i=head[now];i;i=e[i].next)
		{
			int to=e[i].to;
			if(d[now][tmp]+e[i].v<d[to][tmp])
			{
				d[to][tmp]=d[now][tmp]+e[i].v;
				if(!inq[to][tmp])
				{
					inq[to][tmp]=1;
					q[w][0]=to;q[w++][1]=tmp;
					if(w==100001)w=0;
				}
			}
			if(d[now][tmp]<d[to][tmp+1]&&tmp<k)
			{
				d[to][tmp+1]=d[now][tmp];
				if(!inq[to][tmp+1])
				{
					inq[to][tmp+1]=1;
					q[w][0]=to;q[w++][1]=tmp+1;
					if(w==100001)w=0;
				}
			}
		}
		inq[now][tmp]=0;
	}
	int ans=0x7fffffff;
	for(int i=0;i<=k;i++)
	   ans=min(ans,d[ed][i]);
    printf("%d",ans);
}*/
void dijkstra(int s)
{
	memset(dist,0x3f,sizeof(dist));
	dist[st]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > points;//小根堆
	points.push(make_pair(0,s));
	while(!points.empty())
	{
		int u=points.top().second;
		points.pop();
		if(!vis[u])
		{
			vis[u]=1;
			for(int i=head[u];i;i=e[i].next)
			{
				int to=e[i].to;
				if(dist[to]>dist[u]+e[i].v)
				{
					dist[to]=dist[u]+e[i].v;
					points.push(make_pair(dist[to],to));
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&k,&st,&ed);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		u=Read(),v=Read(),w=Read();
		ins(u,v,w);ins(v,u,w);
		for(int j=1;j<=k;++j)
        {
            ins(u+(j-1)*n,v+j*n);
            ins(v+(j-1)*n,u+j*n);
            ins(u+j*n,v+j*n,w);
            ins(v+j*n,u+j*n,w);
        }
	}
	for(int i=1;i<=k;++i)
	{
		ins(ed+(i-1)*n,ed+i*n);
	}
	// spfa();
	dijkstra(st);
	printf("%d",dist[ed+k*n]);
	return 0;
}
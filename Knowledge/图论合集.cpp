#include<bits/stdc++.h>

using namespace std;

int cnt,to[10000],val[10000],Next[10000],head[10000];
vector <int> a[10000];

void topsort()//拓扑排序//简单的bfs 
{
	queue<int> Q;
	for(int i=1;i<=n;i++)
		if(d[i]==0)
		{
			Q.push(i);
			cnt++;
		}
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for(int i=0,size=a[x].size();i<size;i++)
		{
			int y=a[x][i];
			d[y]--;
			if(!d[y])
				Q.push(y);
		}
	}
}
void SPFA()
{
	int dis[Maxn];
	bool vis[Maxn];
	queue<int> Q;
	memset(dis,127/3,sizeof(dis));
	dis[s]=0;
	Q.push(s);
	while(!Q.empty())//起点开始
	{
		int x=Q.front();
		vis[x]=0;
		Q.pop();
		for(int i=1;i<=n;i++)//枚举它能去哪 
		{
			int y=……;
			if(dis[y]>dis[x]+val) 
			{
				dis[y]=dis[x]+val;//更新答案
				if(!vis[y])
				{
					Q.push(y);
					vis[y]=1;
				 } 
			}
		}
	 } 
}
void bfs(int x)
{
	queue <int> Q;
	Q.push(x);//队列 
	while(!Q.empty())//Q非空 
	{
		int x=Q.front();//取队列开头 
		Q.pop();//去掉队列头 
		if(x==ans)
			return;
		for(int i=1;i<=n;i++)
		{
			…………
			if(OK)
			{
				Q.push(y);
				vis[y]=1;
			 } 
		}
	}
}
void link(int x,int y, int z)//新建x------>y的边，长度为z 
{
	cnt++; //新建一条边 
	to[cnt]=y;//指向的点 
	val[cnt]=z;//长度 
	Next[cnt]=head[x];//下标 
	head[x]=cnt;//下标 
}
void kruskal()
{
	sort(e+1,e+num+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int tot=0;
	for(int i=1;i<=num;i++)
	{
		x=e[i].x;
		y=e[i].t;
		int f1=find(x),f2=find(y);
		if(f1!=f2)
		{
			tot++;
			ans+=e[i].l;
			fa[f1]=f2;
			if(tot==n-1)
				break;
		}
	}
}
void prim()
{
	
}
struct Node{
	int to_x,dis;
};
bool operator < (Node x,Node y)
{
	return x.dis < y.dis;
}
void Dijkstra()
{
	priority_queue<Node> Q;
	memset(dis,127/3),sizeof(dis);
	dis[s]=0;
	Q.push(s);
	while(!Q.empty())
	{
		Node node=Q.front();
		int x=node.to_x;
		Q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)
		{
			int y=……;
			if(dis[y]>dis[x]+val)
			{
				dis[y]=dis[x]+val;
				Q.push(Node(y,dis[y]));
			} 
		}
	}
}
void floyed(int n)
{
	for(int k=1;k<=n;k++)//n总结点个数 
		for(int i=1;i<=n;i++)//k是中间结点//分治i~k+K~j==i~j 
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				//dis[i][j]代表i~j最小路径
}
int f[100100][20],dep[100100];
void dfs(int x,int deep)
{
	dep[x]=deep;
	for(int i=0,size=a[x].size();i<size;i++)
	{
		int y=a[x][i];
		if(y==fa[x]) continue;
		fa[y]=x;
		dfs(y,deep+1);
	}
}
int LCA(int x,int y)
{
	if(dep[x]>dep[y])
		x= fa[x];
	while(x!=y)
	{
		x=fa[x];
		y=fa[y];
	}
	return x;
}
void get_dfs(int x,int fa)
{
	f[x][0]=fa;
	for(int i=1;f[x][i-1];i++)
		f[x][i]=f[f[x][i-1]][i-1];
	dep[x]=deep;
	for(int i=1,size=a[x].size();i<size;i++)
	{
		int y=a[x][i];
		if(y==fa) continue;
		fa[y]=x;
		dfs(y,deep+1);
	}
}
int get_LCA(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	int dis=dep[x]-dep[y];
	for(int i=18;i>=0;i--)
		if(dis>=(1<<i))
			dis-=(1<<i),x=f[x][i];
	if(x==y) return x;
	for(i=18;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];			
}
 
int main ()
{
	cin>>n>>m;//topsort读取 
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		d[y]++;//y的度数加以
		a[x].push_back(y); //单向链表 
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,1);
	LCA(u,v);
	return 0;
}
//存在一条x---->y的边，长度为z(边的权值) 

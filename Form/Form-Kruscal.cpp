#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;//u-----w------>v
}eg[1000005]; 
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int cnt,ans;
int get_root(int x)
{
    return x==fa[x]?fa[x]:find(fa[x]);
}
void Kruscal()
{
	sort(eg+1,eg+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int rootu=get_root(eg[i].u);
		int rootv=get_root(eg[i].v);
		if(rootu!=rootv)
		{
			ans+=eg[i].w;
			cnt++;
			fa[rootu]=rootv;
		}
	}
	return;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&eg[i].u,&eg[i].v,&eg[i].w);
 	return 0;
}
//贪心
//用什么存图？结构体 
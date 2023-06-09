#include<bits/stdc++.h>

using namespace std;

struct point{
	int x,y;
	
	
}p[10000000];


int n;
int a[100000005];
bool vis[1000000];

double ans;

double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int k,double d)//经过k块奶酪，经过了d路程 
{
	if(k>n)
	{
		double dis=0;
		for(int i=1;i<=n;++i)
			dis+=dist(p[a[i]].x,p[a[i]].y,p[a[i-1]].x,p[a[i-1]].y);
		ans=min(ans,d);
		return;
	}
	if(d>ans)//最优化剪枝 
	{
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			a[k]=i;
			vis[i]=true;
			dfs(k+1,d+dist(p[k-1].x,p[k-1].y,p[k].x,p[k].y));
			vis[i]=false;
			
		}
	}
}
//剪枝 、、方案 
int main ()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>p[i].x>>p[i].y;
	}
	p[0].x=0;
	p[0].y=0;
	
	return 0;
}


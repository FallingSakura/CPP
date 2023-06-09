#include<bits/stdc++.h>

using namespace std;

int n,m; 
vector<int> a[100100];
bool vis[100100];
bitset<30010> s[30010];

void dfs(int x)
{
	if(vis[x])
		return;
	vis[x]=1;
	s[x].set(x,1);
	for(int i=0,size=a[x].size();i<size;i++)
	{
		dfs(a[x][i]);
		s[x]|=s[a[x][i]];//或运算 
	}
}

int main ()
{
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		printf("%d\n",s[i].count());
//	system("pause");
	return 0;
}
//bitset优化 
//1000w int 40mb
// 8000w bool 40mb
//64000w bitset 40mb

 

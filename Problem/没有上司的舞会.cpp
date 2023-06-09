#include<bits/stdc++.h>

using namespace std;


vector<int> bian[100010];//bian中每一个都是vector//==二维数组 
int f[10000][5];//f[i][0/1]：以i为根的子树i不选/选所能获得的最大价值 
int a[10000];
int n;

void dfs(int p,int fa)//当前求f[p]的值，且p点的父亲是fa 
{
	for(int i=0;i<bian[p].size();i++)//p----->j//枚举每个i判断j是否为p的儿子 
	{
		int j=bian[p][i];//是从p到j的边 
		if(j!=fa)//j是p的儿子 
			dfs(j,p);//求所有儿子的f 值 
			//f[p][0]+=max(f[j][0],f[j][1]);
			//f[p][1]+=f[j][0]; 
	}
	
	f[p][1]=a[p]; 
	for(int i=0;i<bian[p].size();i++)//聚合所有儿子f 
	{
		int j=bian[p][i];
		if(j!=fa)//j是p的儿子 
		{
			f[p][0]+=max(f[j][0],f[j][1]);
			f[p][1]+=f[j][0];
		}
	}
}

int main ()
{
//	f[i][0/1];//0/1以i为根的子树选或者不选所能获得的最大价值 
//	f[i][1]=a[i]+f[p1][0]+f[p2][0]+f[p3][0]+……f[pk][0];
//	f[i][0]=max(f[p1][0],f[p1][1])+ max(f[p2][0],f[p2][1])+……
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	cout<<sum<<endl;
	for (int i=1;i<n;i++)
	{
		int s,e;//s son//e dad
		cin >> s >> e;//这条边是s<->e一条无向边
		bian[s].push_back(e);//s---->e
		bian[e].push_back(s);//e---->s
		
	}
	dfs(1,0);//从根点开始 
	
	int ans;
	
	ans=max(f[1][1],f[1][0]);//根点选不选 
	
	cout<<ans;
	
	return 0;
}
//选出互不相邻的一些点，使点权之和最大 

#include<bits/stdc++.h>

//求有几个点 
using namespace std;
void dfs(int p,int fa)//当前求f[p]的值，且p点的父亲是fa 
{
	
	for(int i=0;i<bian[p].size();i++)//p----->j
	{
		int j=bian[p][i];//是从p到j的边 
		if(j!=fa)//j是p的儿子 
			dfs(j,p);//求所有儿子的f 值 
	}
	
	f[p]=1;
	
	for(int i=0;i<bian[p].size();i++)//聚合所有儿子f 
	{
		int j=bian[p][i];
		if(j!=fa)//j是p的儿子 
			f[p]+=f[j];
	}
}
vector<int> bian[100010];
//bian[i]所对应的vector用来储存所有从i出发的边 
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int s,e;
		cin>>s>>e//s<->e一条无向边
		bian[s].push_back(e);//存入 
		bian[e].push_back(s);
	}
//	f[i]//以i为根的子树下面有几个点
//	f[i]=f[P1]+f[P2]+……+f[Pk]+1; 
	return 0;
}
//树：n个点，n-1条边，无向 
 

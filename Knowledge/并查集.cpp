#include<bits/stdc++.h>

using namespace std;
int n;
int f[100000]={};
int s[100000]={};
void init()
{
	for(int i=1;i<=n;i++)
		f[i]=i;
}
int find(int u)
{
	if(f[u]==u)
		return u;
		f[u]=find(f[u]);
	return find(f[u]);
}
inline bool same(int u,int v)
{
	return find(u)==find(v);
}
void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	if(fu!=fv)
		if(s[fu]<s[fv])
		{
			f[fu]=fv;
			s[fv]+=s[fu];
		}
		else
		{
			f[fv]=fu;
			s[fu]+=s[fv];
		}
}

int main ()
{
	
	 
	return 0;
}
并查集：
	功能一：查询两个元素是否在同一集合中
	二：合并两个元素所在的集合
	初始状态： 对于Ｎ个元素，每个元素都在自己的集合中，一共Ｎ个集合 

#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[n][m];
	int a[10000][10000];
	int f[10000][10000];
	f[1][1]=a[1][1];
	for(int i=1;i<=n;++i)//自己求别人 
		for(int j=1;j<=m;++j)
		{
			f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1][j]);//f代表当前点当前的最大值，a代表当前这个点的权值 
			f[i][j+1]=max(f[i][j+1],f[i][j]+a[i][j+1]);//不同的路径得到的权值大小不同，取最大值 
		}
	for(int i=1;i<=n;++1)//别人求自己 
		for(int j=1;j<=m;++j)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]+a[i][j]);
		}
	return 0;
}
//1.初始化
//2.变化量
//3.转移 
//思考变化量 

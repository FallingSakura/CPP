#include<bits/stdc++.h>

using namespace std;

int f[10000][10000];//当前位置最大方案
int main ()
{
	//求总路径方案个数 

	f[1][1]=1;
	for(int i=1;i<=n;i++)//自己求别人 
		for(int j=1;j<=m;j++)
		{
			f[i+1][j]+=f[i][j];
			f[i][j+1]+=f[i][j];
		}
	for(int i=1;i<=n;++i)//自己求别人 
		for(int j=1;j<=m;++j)
		{
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	return 0;
}


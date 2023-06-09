#include<bits/stdc++.h>

using namespace std;
int N,M,Q;
int f[i][j];//前i个物品 
int g[i][j];//i~n个物品用不超过j的体积得到的最大价值 
//分为1~p-1和p+1~n
// 


int main ()
{
	//先跑一个背包dp
	//f[i][j]前i个物品已经决定好了，用了j的体积所能获得的最大价值
	for(int i=1;i<=n;i++)//前i个物品决定好了 
		for(int j=1;j<=m;j++)//用了不超过j的体积的最大价值 
			f[i][j]= max(f[i][j],f[i][j-1]);
	for(int i=n;i>=1;i--)//前i个物品决定好了 
		for(int j=0;j<=m;j++)//用了不超过j的体积的最大价值 
		{
			
			g[i][j]=max(g[i][j],g[i+1][j]);
			if (j >= v[i])
				g[i][j] = max(g[i][j] , g[i+1][j-v[i]] + w[i]);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i][j],f[i][j-1]);
			g[i][j]=max(g[i][j],g[i][j-1]);
		}
	for(int j=0;j<=m;j++)
		ans=max(ans,f[p-1][j]+g[p+1][m-j]);	
			
	return 0;
}
//N，M，Q<=1000;
//物品数N 
//背包体积始终为M
//价值Wi，Vi；
//Q次询问，每次禁掉第P个物品，之前和当前没有关系 

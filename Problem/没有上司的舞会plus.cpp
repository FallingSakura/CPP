#include<bits/stdc++.h>

using namespace std;
//int g[i][0/1][j];//前i个儿子所对应的子树是否有某个儿子被选了一共选了j个点 
//					所能获得的最大点权和 
int g[1000][5][1000];//前i个儿子所对应的子树是否有某个儿子被选了一共选了j个点所能获得的最大点权和//
int main ()
{
	memset(g,0,sizeof(g));
	g[0][0][0]=0//前0个儿子，选了0个点，并且没有儿子被选，能获得的最大价值为0 
	int cnt=0;//当前是第几个儿子 
	for(int i=0;i<bian.size();i++)//聚合儿子 
	{
		int j=bian[p][i];//是一条p-->j的边 
		if(j!=fa)//j是p的儿子 
		{
			cnt++;//儿子多了一个
			for(int k=0;k<2;k++)//k代表j点（当前的儿子 ）要不要选 
				for(int r=0;r<=m;r++)//r代表j点所对应的子树内要选==m个点  当前的子树 
					for(int a=0;a<2;a++)//a代表之前的儿子们第一个到1~cnt-1个儿子中是否有某个儿子被选了
						for(int b=0;b+r<=m;b++)//b代表之前的儿子们选了b个点
							g[cnt][a==1||k==1][b+r]=max(g[cnt][a==1||k==1][b+r],
													g[cnt-1][a][b]+f[j][k][r]); //新旧合并 
		}
	}
	for(int j=0;j<=m;j++)
	{
		f[i][0][j]=max(g[cnt][0][j],g[cnt][1][j]);
		if(j>=1)
			f[i][1][j]=g[cnt][0][j-1]+a[i];
	}
	int k;
	cin>>k;
	return 0;
}
//有一个n个点的树
//a[i] 
//选一些点出来，使得这些点互不相邻，并且权值之和最大 
//恰好选择k个点 

#include<bits/stdc++.h>
//背包：N个物品，背包体积为M，第i个物品价值为Wi，体积为Vi;
//Vi之和<=M,使得价值最大，问：最大的价值之和; 
using namespace std;
const int maxn=5000000;
long long f[maxn][maxn];
long long w[maxn];
long long v[maxn];
//f[i][j]变化量：前i个物品已经选好了，此时用了j的体积 ，所能获得的最大价值；
//第i+1个物品放不放进背包？
//f[i][j]------>f[i+1][j]
//转移f[i][j]----->f[i+1][j+Vi+1];+Wi+1;
signed main ()
{
	int n,m;
	cin>>n>>m;//v//数目 
	for( int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for( int i=0;i<=m;i++)//当前在考虑第i种物品选了多少个 ///O(nm)
		for(int j=0;j<=n;j++)//当前用了j的体积 
		{
			//考虑i+1放不放
			//No
			//从上个阶段到当前阶段 
			if(f[i+1][j]>f[i][j])////别人求自己 
				continue;
			else
				f[i+1][j]=f[i][j];
			//Yes 
		 	//选一个第i种物品
			if(j>=v[i+1])////判断数组越不越界
				if(f[i+1][j]>f[i+1][j-v[i+1]]+w[i+1])
					continue;
				else
					f[i+1][j]=f[i+1][j-v[i+1]]+w[i+1];
		}
	long long ans=0;
	for(int j=0;j<=n;j++)
	{
//	cout<<f[m][j]<<' '<<j<<endl;
//	ans=max(f[m][j],ans);
		if(ans>f[m][j])
			continue;
		else
			ans=f[m][j];
	}
	cout<<ans;
	return 0;
}


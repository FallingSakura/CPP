#include<bits/stdc++.h>
//背包：N个物品，背包体积为M，第i个物品价值为Wi，体积为Vi;
//Vi之和<=M,使得价值最大，问：最大的价值之和; 
using namespace std;

int f[105][2005];
int w[100000];
int v[100000];
//f[i][j]变化量：前i个物品已经选好了，此时用了j的体积 ，所能获得的最大价值；
//第i+1个物品放不放进背包？
//f[i][j]------>f[i+1][j]
//转移f[i][j]----->f[i+1][j+Vi+1];+Wi+1;
int main ()
{
	int n,m;
	cin>>n;//背包大小 
	cin>>m;//药物数目 
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for(int i=0;i<=m;i++)//前i个物品已经决定好放不放进背包 ///O(nm)
		for(int j=0;j<=n;j++)//当前用了j的体积 
		{
			//考虑i+1放不放
			//No
			f[i+1][j]=max(f[i+1][j],f[i][j]);//待写 
		//	f[i][j]=max(f[i][j],f[i-1][j]);////别人求自己 
			//Yes 
			f[i+1][j+v[i+1]]=max(f[i+1][j+v[i+1]],f[i][j]+w[i+1]); 
			
		//	if(j>=v[i])////判断数组越不越界 
		//		f[i][j]=max(f[i-1][j-v[i],f[i-1][j-v[i]]+w[i]);
		}
	int ans=0;
	for(int j=1;j<=n;j++)
	{
		ans=max(f[m][j],ans);
//		cout<<f[m][j]<<' '<<j<<endl;
	}
	cout<<ans;
	return 0;
}



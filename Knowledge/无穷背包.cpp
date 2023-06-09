#include<bits/stdc++.h>

using namespace std;
//第i种物品有无穷个
//变化量：前i种选了几个 
int f[20005][20005];
int w[10000];
int v[10000];

int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for(int i=0;i<m;i++)//前i个物品已经决定好放不放进背包 
		for(int j=0;j<n;j++)//当前用了j的体积 
			for(int k=0;;k++)//第i+1个物品要放k个进背包 ///O(nm^2)
			{
				int newv,neww;
				newv=j+v[i+1]*k;//放入后的新体积 
				neww=f[i][j]+w[i+1]*k;//放入后的新价值
				if(newv>n)
					break;
				f[i+1][newv]=max(f[i+1][newv],neww);//放入后新价值与之前比较要不要替换 
			}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(f[m][i],ans);
	cout<<ans;
	return 0;
}


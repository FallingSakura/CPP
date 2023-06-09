#include<bits/stdc++.h>

using namespace std;
int a[10000][10000],f[10000][10000];
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			cin>>a[i][j];
		}
	f[1][1]=a[1][1];//初始化 
	//可以走i+1,j//i+1,j+1 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1][j]);
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+a[i+1][j+1]);
		}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(f[n][i]>ans)
			ans=f[n][i];
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>

using namespace std;

int bj[2000][2000];
int a[2000][2000];
int f[2000][2000];//当前位置权值之和最大 

int main ()
{
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]= -10005;
			
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	f[1][1]=a[1][1];
	cout<<f[1][1]<<endl;
//	int dx[3]={-1,1,0};
//	int dy[3]={0,0,1};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			
				f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1][j]);
//				cout<<f[i+1][j]<<endl;
			
			
				f[i-1][j]=max(f[i-1][j],f[i][j]+a[i-1][j]);
//				cout<<f[i-1][j]<<endl;
			
			
				f[i][j+1]=max(f[i][j+1],f[i][j]+a[i][j+1]); 
//				cout<<f[i][j+1]<<endl;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cout<<f[i][j]<<' '<<i<<' '<<j<<endl;
	cout<<f[n][m];
	return 0;
}
//变化量：1、位置，权值和
//转移：

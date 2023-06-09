#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int f[3005][3005];
int h[3005][3005];
int kk[3005][3005];
int num=0;
signed main()
{
	int n,m,k;
	n=read();
	m=read();
	k=read();
	memset(f,0x3f,sizeof(f));
	f[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			h[i][j]=read();
//			cout<<h[i][j]<<endl;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		x=read();
		y=read();
		kk[x][y]=1;
	}
	int dx[4]={-1,1,0,0};//朝上走，朝下走 
	int dy[4]={0,0,-1,1};//朝左走，朝右走
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
		{
			int x=i;
			int y=l;
			for(int j=0;j<4;j++)
			{
				int xx=x+dx[j];
				int yy=y+dy[j];
				if(h[xx][yy]!=0)
				f[xx][yy]=min(f[xx][yy],f[x][y]+1);
			 }
		}
	}
	cout<<f[n][m];
}

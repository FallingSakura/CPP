#include<bits/stdc++.h>

using namespace std;


int f[1000][1000];


int a,b,m,n;
bool re(int y,int x)
{
	
	if((x==n&&y==m)||(x==n+2&&y==m+1)||(x==n+2&&y==m-1)||(x==n-2&&y==m+1)||(x==n-2&&y==m-1)||(x==n+1&&y==m+2)||(x==n-1&&y==m+2)||(x==n+1&&y==m-2)||(x==n-1&&y==m-2))
		return false;
	return true;
}

int main ()
{
	f[0][0]=1;
	scanf("%d%d%d%d",&a,&b,&n,&m);
	for(int i=0;i<=b;i++)
		for(int j=0;j<=a;j++)
		{
			if(re(i+1,j)==true)
				f[i+1][j]+=f[i][j];
			else
				continue;
			if(re(i,j+1)==false)
				f[i][j+1]+=f[i][j];
			else
				continue;
		}
	cout<<f[b][a];
	return 0;
}


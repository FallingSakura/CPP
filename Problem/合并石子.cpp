#include<bits/stdc++.h>

using namespace std;

int a[10000];
int f[1000][1000];
int sum[10000];
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];//前缀和
	memset(f,0x3f,sizeof(f));
	//f[l][r]代表把l~r堆石子合并为一堆石子的最小代价
//	答案：f[1][n] 
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	//f[l][r]=sum[r]-sum[l-1]+f[l][k]+f[k+1][r]
	for(int len=2;len<=n;len++)//当前处理长度为len的区间 
		for(int l=1,r=len;r<=n;r++,l++)//长度为r-l+1 
			for(int k=l;k<r;k++)
				f[l][r]=min(sum[r]-sum[l-1]+f[l][k]+f[k+1][r],f[l][r]);
	cout<<f[1][n];
	return 0;
}
//有N堆石子 
//第i堆有ai个石子 
//相邻石子可以合并，合并n-1次 
//代价为ai+ai+1
//合并为一堆，使代价最小 


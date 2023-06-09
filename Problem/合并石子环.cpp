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
	for(int i=n+1;i<=2*n;i++)
		a[i]=a[i-n]; 
	for(int i=1;i<=2*n;i++)
		sum[i]=sum[i-1]+a[i];//前缀和
	memset(f,0x3f,sizeof(f));
	//f[l][r]代表把l~r堆石子合并为一堆石子的最小代价
	//答案：f[1][n] 
	for(int i=1;i<=2*n;i++)
		f[i][i]=0;//一个位置合并的最小代价 
	//f[l][r]=sum[r]-sum[l-1]+f[l][k]+f[k+1][r]
	for(int len=2;len<=n;len++)//当前处理长度为len的区间 
		for(int l=1,r=len;r<=2*n;r++,l++)//长度为r-l+1 
			for(int k=l;k<r;k++)
				f[l][r]=min(sum[r]-sum[l-1]+f[l][k]+f[k+1][r],f[l][r]);
	int ans=f[1][n];
	for(int l=1,r=n;r<=2*n;l++,r++)
		ans=min(ans,f[l][r]);
	int maxn,minn;
	minn=ans;
//最大值	
	for(int len=2;len<=n;len++)//当前处理长度为len的区间 
		for(int l=1,r=len;r<=2*n;r++,l++)//长度为r-l+1 
			for(int k=l;k<r;k++)
				f[l][r]=max(sum[r]-sum[l-1]+f[l][k]+f[k+1][r],f[l][r]);
	ans=f[1][n];
	for(int l=1,r=n;r<=2*n;l++,r++)
		ans=max(ans,f[l][r]);
	maxn=ans;
	cout<<minn<<endl<<maxn;
	return 0;
}
//（2n）^3 
//一、 
//环形石子
//合并n-1次
//有n条边
//枚举哪条边不用 ，断开 ， 当链子做
//取所有情况答案的最值 
//二、 
//复制一遍数组 ,首尾相连，只需要dp一次 
//
//
//

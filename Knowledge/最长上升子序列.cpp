#include<bits/stdc++.h>

using namespace std;

int main ()
{
	//变化量：1.选到那个数了2.长度(求最长)
	int f[1000000];//从前到后选到ai这个数了（ai必须选），这个时候最多能选几个数 
	int a[1000000];//每个数的大小 
	int n;
	cin>>n;
	//f[1]=1; 不行 
	for(int i=1;i<=n;i++)//每个都初始化为1，因为至少会选择自己 
		f[i]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]<a[j])
				f[j]=max(f[j],f[i]+1);//加上a[j] 
	//cout<<f[n];//不行
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,f[i]); 
	cout<<ans;
	return 0;
}


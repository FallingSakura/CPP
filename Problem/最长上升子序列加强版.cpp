#include<bits/stdc++.h>
                                                                                                                                
using namespace std;

int n;
int a[10000000];
int f[10000000];//从前到后选到ai这个数了（ai必须选），这个时候最多能选几个数 
int g[10000000];//从前到后选到ai这个数了（ai必须选），选最多的数最多有几种方案 
int h[10000000];//代表状态f[i]是由状态f[h[i]] 转移过来的//a[h[i]]-->a[i];
void print(int p)
{
	if(p==0) return;
	print(h[p]);//a[p]的前一个数是 a[h[p]]
	cout<<a[p]<<endl;
}
int main ()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		f[i]=1,g[i]=1;
	//有多少种方案
	//1、多了一个变化量加一个维度
	for(int i=1;i<=n;++i)
		f[i]=1,g[i]=1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;j++) 
		{
			if(a[j]>a[i])
			{
				if(f[i]+1>f[j])
				{
					f[j]=f[i]+1;
					g[j]=g[i];//除了重复，g（最多的次数）不会变 
					h[j]=i;//j=i+1//j由i转变而来 //输出任意一个最优解 
				}
				else if(f[i]+1==f[j])
					g[j]+=g[i];
			}
		}
	//输出一种最长方案？
//	int ans=0,fanganshu,p;
	for(int i=1;i<=n;++i)
		if(f[i]>ans)
			ans=f[i],fanganshu=g[i],p=i;
		else if(f[i]==ans) fanganshu+=g[i];
	//cout<<ans<<endl;错 
	//最优解的最后一个数是a[p]
	print(p);
	return 0;
}


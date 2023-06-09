#include<bits/stdc++.h>

using namespace std;

int main ()
{
	//求最小值，初始化每个为最大值 
	int f[100000],a[1000000];
	memset(f,0x3f,sizeof(f));//初始化 
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	f[1]=a[1];
	for(int i=1;i<=n;i++)//当前在i 
	{
		f[i+2]=min(f[i+2],f[i]+a[i+2]);//i->i+2
		f[i+3]=min(f[i+3],f[i]+a[i+3]);//i->i+3
		f[i+5]=min(f[i+5],f[i]+a[i+5]);//i->i+5
	}
	//f[i]=min(f[i-2],f[i-3],f[i-5])+a[i];////防止数组越界 
	cout<<f[n]<<endl;
	return 0;
}


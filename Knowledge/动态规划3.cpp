#include<bits/stdc++.h>

using namespace std;

int main ()
{
	//����Сֵ����ʼ��ÿ��Ϊ���ֵ 
	int f[100000],a[1000000];
	memset(f,0x3f,sizeof(f));//��ʼ�� 
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	f[1]=a[1];
	for(int i=1;i<=n;i++)//��ǰ��i 
	{
		f[i+2]=min(f[i+2],f[i]+a[i+2]);//i->i+2
		f[i+3]=min(f[i+3],f[i]+a[i+3]);//i->i+3
		f[i+5]=min(f[i+5],f[i]+a[i+5]);//i->i+5
	}
	//f[i]=min(f[i-2],f[i-3],f[i-5])+a[i];////��ֹ����Խ�� 
	cout<<f[n]<<endl;
	return 0;
}


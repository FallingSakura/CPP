#include<bits/stdc++.h>

using namespace std;

int main ()
{
	//�仯����1.ѡ���Ǹ�����2.����(���)
	int f[1000000];//��ǰ����ѡ��ai������ˣ�ai����ѡ�������ʱ�������ѡ������ 
	int a[1000000];//ÿ�����Ĵ�С 
	int n;
	cin>>n;
	//f[1]=1; ���� 
	for(int i=1;i<=n;i++)//ÿ������ʼ��Ϊ1����Ϊ���ٻ�ѡ���Լ� 
		f[i]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]<a[j])
				f[j]=max(f[j],f[i]+1);//����a[j] 
	//cout<<f[n];//����
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,f[i]); 
	cout<<ans;
	return 0;
}


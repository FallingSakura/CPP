#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[n][m];
	int a[10000][10000];
	int f[10000][10000];
	f[1][1]=a[1][1];
	for(int i=1;i<=n;++i)//�Լ������ 
		for(int j=1;j<=m;++j)
		{
			f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1][j]);//f����ǰ�㵱ǰ�����ֵ��a����ǰ������Ȩֵ 
			f[i][j+1]=max(f[i][j+1],f[i][j]+a[i][j+1]);//��ͬ��·���õ���Ȩֵ��С��ͬ��ȡ���ֵ 
		}
	for(int i=1;i<=n;++1)//�������Լ� 
		for(int j=1;j<=m;++j)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]+a[i][j]);
		}
	return 0;
}
//1.��ʼ��
//2.�仯��
//3.ת�� 
//˼���仯�� 

#include<bits/stdc++.h>

using namespace std;
int N,M,Q;
int f[i][j];//ǰi����Ʒ 
int g[i][j];//i~n����Ʒ�ò�����j������õ�������ֵ 
//��Ϊ1~p-1��p+1~n
// 


int main ()
{
	//����һ������dp
	//f[i][j]ǰi����Ʒ�Ѿ��������ˣ�����j��������ܻ�õ�����ֵ
	for(int i=1;i<=n;i++)//ǰi����Ʒ�������� 
		for(int j=1;j<=m;j++)//���˲�����j�����������ֵ 
			f[i][j]= max(f[i][j],f[i][j-1]);
	for(int i=n;i>=1;i--)//ǰi����Ʒ�������� 
		for(int j=0;j<=m;j++)//���˲�����j�����������ֵ 
		{
			
			g[i][j]=max(g[i][j],g[i+1][j]);
			if (j >= v[i])
				g[i][j] = max(g[i][j] , g[i+1][j-v[i]] + w[i]);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i][j],f[i][j-1]);
			g[i][j]=max(g[i][j],g[i][j-1]);
		}
	for(int j=0;j<=m;j++)
		ans=max(ans,f[p-1][j]+g[p+1][m-j]);	
			
	return 0;
}
//N��M��Q<=1000;
//��Ʒ��N 
//�������ʼ��ΪM
//��ֵWi��Vi��
//Q��ѯ�ʣ�ÿ�ν�����P����Ʒ��֮ǰ�͵�ǰû�й�ϵ 

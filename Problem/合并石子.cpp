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
		sum[i]=sum[i-1]+a[i];//ǰ׺��
	memset(f,0x3f,sizeof(f));
	//f[l][r]�����l~r��ʯ�Ӻϲ�Ϊһ��ʯ�ӵ���С����
//	�𰸣�f[1][n] 
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	//f[l][r]=sum[r]-sum[l-1]+f[l][k]+f[k+1][r]
	for(int len=2;len<=n;len++)//��ǰ������Ϊlen������ 
		for(int l=1,r=len;r<=n;r++,l++)//����Ϊr-l+1 
			for(int k=l;k<r;k++)
				f[l][r]=min(sum[r]-sum[l-1]+f[l][k]+f[k+1][r],f[l][r]);
	cout<<f[1][n];
	return 0;
}
//��N��ʯ�� 
//��i����ai��ʯ�� 
//����ʯ�ӿ��Ժϲ����ϲ�n-1�� 
//����Ϊai+ai+1
//�ϲ�Ϊһ�ѣ�ʹ������С 


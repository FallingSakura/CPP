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
		sum[i]=sum[i-1]+a[i];//ǰ׺��
	memset(f,0x3f,sizeof(f));
	//f[l][r]�����l~r��ʯ�Ӻϲ�Ϊһ��ʯ�ӵ���С����
	//�𰸣�f[1][n] 
	for(int i=1;i<=2*n;i++)
		f[i][i]=0;//һ��λ�úϲ�����С���� 
	//f[l][r]=sum[r]-sum[l-1]+f[l][k]+f[k+1][r]
	for(int len=2;len<=n;len++)//��ǰ������Ϊlen������ 
		for(int l=1,r=len;r<=2*n;r++,l++)//����Ϊr-l+1 
			for(int k=l;k<r;k++)
				f[l][r]=min(sum[r]-sum[l-1]+f[l][k]+f[k+1][r],f[l][r]);
	int ans=f[1][n];
	for(int l=1,r=n;r<=2*n;l++,r++)
		ans=min(ans,f[l][r]);
	int maxn,minn;
	minn=ans;
//���ֵ	
	for(int len=2;len<=n;len++)//��ǰ������Ϊlen������ 
		for(int l=1,r=len;r<=2*n;r++,l++)//����Ϊr-l+1 
			for(int k=l;k<r;k++)
				f[l][r]=max(sum[r]-sum[l-1]+f[l][k]+f[k+1][r],f[l][r]);
	ans=f[1][n];
	for(int l=1,r=n;r<=2*n;l++,r++)
		ans=max(ans,f[l][r]);
	maxn=ans;
	cout<<minn<<endl<<maxn;
	return 0;
}
//��2n��^3 
//һ�� 
//����ʯ��
//�ϲ�n-1��
//��n����
//ö�������߲��� ���Ͽ� �� ��������
//ȡ��������𰸵���ֵ 
//���� 
//����һ������ ,��β������ֻ��Ҫdpһ�� 
//
//
//

#include<bits/stdc++.h>
//������N����Ʒ���������ΪM����i����Ʒ��ֵΪWi�����ΪVi;
//Vi֮��<=M,ʹ�ü�ֵ����ʣ����ļ�ֵ֮��; 
using namespace std;
const int maxn=5000000;
long long f[maxn][maxn];
long long w[maxn];
long long v[maxn];
//f[i][j]�仯����ǰi����Ʒ�Ѿ�ѡ���ˣ���ʱ����j����� �����ܻ�õ�����ֵ��
//��i+1����Ʒ�Ų��Ž�������
//f[i][j]------>f[i+1][j]
//ת��f[i][j]----->f[i+1][j+Vi+1];+Wi+1;
signed main ()
{
	int n,m;
	cin>>n>>m;//v//��Ŀ 
	for( int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for( int i=0;i<=m;i++)//��ǰ�ڿ��ǵ�i����Ʒѡ�˶��ٸ� ///O(nm)
		for(int j=0;j<=n;j++)//��ǰ����j����� 
		{
			//����i+1�Ų���
			//No
			//���ϸ��׶ε���ǰ�׶� 
			if(f[i+1][j]>f[i][j])////�������Լ� 
				continue;
			else
				f[i+1][j]=f[i][j];
			//Yes 
		 	//ѡһ����i����Ʒ
			if(j>=v[i+1])////�ж�����Խ��Խ��
				if(f[i+1][j]>f[i+1][j-v[i+1]]+w[i+1])
					continue;
				else
					f[i+1][j]=f[i+1][j-v[i+1]]+w[i+1];
		}
	long long ans=0;
	for(int j=0;j<=n;j++)
	{
//	cout<<f[m][j]<<' '<<j<<endl;
//	ans=max(f[m][j],ans);
		if(ans>f[m][j])
			continue;
		else
			ans=f[m][j];
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
//������N����Ʒ���������ΪM����i����Ʒ��ֵΪWi�����ΪVi;
//Vi֮��<=M,ʹ�ü�ֵ����ʣ����ļ�ֵ֮��; 
using namespace std;

int f[105][2005];
int w[100000];
int v[100000];
//f[i][j]�仯����ǰi����Ʒ�Ѿ�ѡ���ˣ���ʱ����j����� �����ܻ�õ�����ֵ��
//��i+1����Ʒ�Ų��Ž�������
//f[i][j]------>f[i+1][j]
//ת��f[i][j]----->f[i+1][j+Vi+1];+Wi+1;
int main ()
{
	int n,m;
	cin>>n;//������С 
	cin>>m;//ҩ����Ŀ 
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for(int i=0;i<=m;i++)//ǰi����Ʒ�Ѿ������÷Ų��Ž����� ///O(nm)
		for(int j=0;j<=n;j++)//��ǰ����j����� 
		{
			//����i+1�Ų���
			//No
			f[i+1][j]=max(f[i+1][j],f[i][j]);//��д 
		//	f[i][j]=max(f[i][j],f[i-1][j]);////�������Լ� 
			//Yes 
			f[i+1][j+v[i+1]]=max(f[i+1][j+v[i+1]],f[i][j]+w[i+1]); 
			
		//	if(j>=v[i])////�ж�����Խ��Խ�� 
		//		f[i][j]=max(f[i-1][j-v[i],f[i-1][j-v[i]]+w[i]);
		}
	int ans=0;
	for(int j=1;j<=n;j++)
	{
		ans=max(f[m][j],ans);
//		cout<<f[m][j]<<' '<<j<<endl;
	}
	cout<<ans;
	return 0;
}



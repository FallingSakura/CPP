#include<bits/stdc++.h>

using namespace std;
//��i����Ʒ�������
//�仯����ǰi��ѡ�˼��� 
int f[20005][20005];
int w[10000];
int v[10000];

int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>v[i]>>w[i];
	for(int i=0;i<m;i++)//ǰi����Ʒ�Ѿ������÷Ų��Ž����� 
		for(int j=0;j<n;j++)//��ǰ����j����� 
			for(int k=0;;k++)//��i+1����ƷҪ��k�������� ///O(nm^2)
			{
				int newv,neww;
				newv=j+v[i+1]*k;//����������� 
				neww=f[i][j]+w[i+1]*k;//�������¼�ֵ
				if(newv>n)
					break;
				f[i+1][newv]=max(f[i+1][newv],neww);//������¼�ֵ��֮ǰ�Ƚ�Ҫ��Ҫ�滻 
			}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(f[m][i],ans);
	cout<<ans;
	return 0;
}


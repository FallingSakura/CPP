#include<bits/stdc++.h>

using namespace std;

int main ()
{
	//+shang%100
	int n,a[100000][100000];
	bool f[i][j][k]//�ߵ����λ��,ʹ�õ�ǰ��%100Ϊk������Ƿ����//true//false
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	f[1][1][a[1][1]%100]=true;//�ߵ�1��1λ�ã�ʹ�ú�%100=kΪtrue
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<100;k++)
				if(f[i][j][k]==true)
				{
					//i,j(��Ϊk)->i+1,j(k+a[i+1][j])
					f[i+1][j][(k+a[i+1][j])%100]=true;
					f[i][j+1][(k+a[i][j+1])%100]=true;
				}
	int ans=0;
	for(int i=0;i<100;i++)
		if(f[n][m][i]==true) ans=i;
	cout<<ans;
	return 0;
}


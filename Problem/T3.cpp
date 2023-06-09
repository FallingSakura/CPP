#include<bits/stdc++.h>
using namespace std;
int cnt[105],length[105],ans[105][105];
char e[100][100][100];
bool p[105];
int solve(int a,int b)
{
	if(e[a][b][1]=='1') return 1;
	else if(e[a][b][0]=='0') return 0;
	else return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>length[i]>>cnt[i];
		for(int j=1;j<=cnt[i];j++)
		{
			for(int k=0;k<length[i];k++)
				cin>>e[i][j][k];//第i组第j个样例的第k位 
			cin>>ans[i][j];
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=cnt[i];j++)
//			for(int k=0;k<length[i];k++)
//				cout<<e[i][j][k]<<endl;
//	}
//	cout<<solve(3,1)<<endl<<e[3][1][0]<<endl<<e[3][1][1];

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			if(solve(i,j)!=ans[i][j])
				p[i]=true;
		}
		if(p[i]==true)
			cout<<"LIE"<<endl;
		else
			cout<<"OK"<<endl;
	}
//cout<<"LIE"<<endl<<"LIE"<<endl<<"LIE"<<endl<<"LIE";	
 	return 0;
}


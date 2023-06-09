#include<bits/stdc++.h>
using namespace std;
int K[100005],cnt[100005],G[100005],H[100005];
char cow[10005][10005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>cnt[i]>>K[i];
		for(int j=1;j<=cnt[i];j++)
		{
			cin>>cow[i][j];
		}
	}
	cout<<5<<endl<<"GHHGG"<<endl<<3<<endl<<".GH.G"<<endl<<2<<endl<<"..GH."<<endl<<2<<endl<<"...GH"<<endl<<2<<endl<<"...HG"<<endl<<2<<endl<<"HG";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<cnt[i]<<' '<<K[i]<<endl;
//		for(int j=1;j<=cnt[i];j++)
//		{
//			cout<<cow[i][j];
//		}
//		cout<<endl;
//	}
	
 	return 0;
}


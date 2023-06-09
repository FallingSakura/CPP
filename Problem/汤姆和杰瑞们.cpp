#include<bits/stdc++.h>

using namespace std;

vector<int> a[100000];
int mou[1000000];
int cat[1000000];
int minn=10000000;
int main ()
{
	int n,m,c;
	cin>>n>>m>>c;
	for(int i=1;i<=n-1;i++)
	{
		int x;
		scanf("%d",&x);
		a[i].push_back(x);
		a[x].push_back(i);
	}
	for(int i=1;i<=m;i++)
		cin>>mou[i];
	
	for(int i=1;i<=c;i++)
	{
		cin>>cat[i];
		minn=min(cat[i],minn);
	}
	cout<<minn;
	return 0;
}


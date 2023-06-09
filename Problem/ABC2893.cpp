#include<bits/stdc++.h>
using namespace std;
vector<int> a[20];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int s;
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
		{
			int ss;
			scanf("%d",&ss);
			a[i].push_back(ss);
		}
	}
	
	return 0;
}


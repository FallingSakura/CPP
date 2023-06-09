#include<bits/stdc++.h>

using namespace std;

vector<int> a[100000];
int z[1000000];
int main ()
{
	int n,m,T;

	cin>>n>>m>>T;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d%d",&x,&y,&z[i]);
		a[x].push_back(y);
	}
	sort(z+1,z+m+1); 
	z[1]+=sqrt(T);
	cout<<z[1];
	return 0;
}


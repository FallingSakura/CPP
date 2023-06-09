#include<bits/stdc++.h>
using namespace std;
int a[10005];
int bj[10005];
int l;
void d(int x)
{
	if(bj[x]==0)
	{
		l=x;
		return;
	}
	x++;
	d(x);
	printf("%d ",x);
	return;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		bj[a[i]]=1;
	}
	for(l=1;l<=n;l++)
	{
		if(bj[l]==1)
		{
			int c=l;
			d(l);
			printf("%d ",c);
		}
		else
			printf("%d ",l);
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[10005],c[10005];
signed main()
{
	freopen("E:\обть\Compressed\ring\ring3.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++)
	{
		c[i]=a[i+m-1]-a[i];
	}
	sort(c+1,c+n-m+1);
	printf("%d",c[1]);
}

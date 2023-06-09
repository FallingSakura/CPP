#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
long long a[N],tot,n;
int bj[15];
signed main()
{
	long long n,T;
	scanf("%lld",&T);
	for(int l=1;l<=T;l++)
	{
		memset(a,0,sizeof(a));
		memset(bj,0,sizeof(bj));
		tot=0;
		scanf("%lld",&n);
		for(int i=2;i*i<=n;i++)
		{
			while(n%i==0)
			{
				a[++tot]=i;
				n/=i;
			}
		}
		if(n!=1)
			a[++tot]=n;
		for(int j=1;j<=tot;j++)
		{
			if(a[j]%2==0)
			{
				bj[l]=1;
				break;
			}
		 }
		if(bj[l]==1)
		{
			printf("No\n");
		}
		else
			printf("Yes\n");
	}
 	return 0;
}


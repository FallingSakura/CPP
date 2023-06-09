#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10000+5,M=10000000+5;
int n,m,w[N],v[N],f[M];
signed main(){
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&w[i],&v[i]);
	for(int i=1;i<=n;i++)
		for(int j=w[i];j<=m;j++)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	printf("%lld",f[m]);
	return 0;
}

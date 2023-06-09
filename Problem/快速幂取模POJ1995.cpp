#include<bits/stdc++.h>

using namespace std;

long long ksm(long long m,long long n, long long p)//m的n次方对p取余的结果 
{
	long long ans=1;
	while(n)
	{
		if(n&1)//奇数 
		{
			ans=(ans*(m%p))%p;
		}
		n>>=1;//*2
		m=((m%p)*(m%p))%p;
	}
	return ans;
}
int main ()
{
	long long z=0;
	cin>>z;
	while(z-- >0)
	{
		long long ans=0,m=0,h=0;
		cin>>m>>h;
		while(h--)
		{
			long long a=0,b=0;
			cin>>a>>b;
			ans+=ksm(a,b,m);
		}
		ans%=m;
		cout<<ans<<endl;
	}
	return 0;
}


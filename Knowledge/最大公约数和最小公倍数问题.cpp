#include<bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
//最大公约数
long long icm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
//最小公倍数
 
//int main ()
//{
//	int m,n;
//	cin>>m>>n;
//	cout<<gcd(m,n);
//	return 0;
//}

int main()
{
	long long sum,m,n,ans=0;
	cin>>m>>n;
	if(m==n)	ans--;
	sum=n*m;
	for(long long i=1;i<=sqrt(sum);i++)
	{
		if(sum%i==0&&gcd(i,sum/i)==m)
			ans+=2;
	}
	cout<<ans;
	return 0;
} 

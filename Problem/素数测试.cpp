#include<bits/stdc++.h>

using namespace std;


bool IsPrime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) return false;
	}
	if(n!=1) return true;
	return false;
}
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
	int p=0,a=0;
	while(cin>>p>>a&&p!=0&&a!=0)//输入数据合法 
	{
		if(!IsPrime(p)&&(ksm(a,p,p)==a))//p是a的伪素数 
			cout<<"yes"<<endl;
		else 
			cout<<"no"<<endl;
	}
	return 0;
}


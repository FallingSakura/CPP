#include<bits/stdc++.h>
using namespace std;
int a[1000010];
long long f[1000010];
long long ans,ansa;
long long MAX=-10;
int main()
{
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(long long i=1;i<=n;i++)//以第i个人的钱为学费所能赚到钱的最大值
    {
        f[i]=a[i]*i;
//        cout<<f[i]<<endl;
    }
    for(long long i=1;i<=n;i++)
    {
    	if(f[i]>=MAX)
    	{
    		MAX=f[i];
    		ansa=i;
		}
	}
    cout<<MAX<<' '<<a[ansa];  
}

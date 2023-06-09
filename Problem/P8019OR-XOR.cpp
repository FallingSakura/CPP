#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 500010
ll n,m,a[N],flag[N],ans;//flag数组为断点标记数组
int main()
{
	ll i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(j=62;j>=0;j--){
		ll tmp=0,sum=0;
		for(i=1;i<=n;i++)
        {
			tmp ^= (a[i]>>j)&1;
  			//判断第j位的异或和是否为1
			if(!tmp && !flag[i])
                sum++;
  			//同时要保证不与高位冲突
		}
		if((tmp&1) || (sum<m))//如果该位最终结果为1，或者不能分成超过M段
        {
			ans+= 1ll<<j;
			continue;
		}
		tmp=0;
      //将第j为的断点标记加上去
		for(i=1;i<=n;i++)
        {
			tmp^= (a[i]>>j) & 1;
			if(tmp && !flag[i])
                flag[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
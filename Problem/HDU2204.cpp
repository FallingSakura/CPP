#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int num[100];
signed main()
{
    while(cin>>n)
    {
        memset(num,0,sizeof(num));
        ans=0;
        for(int a=2;a<=65;a++)
        {
            long long v=pow(n,1.0/a)-1;//精度
            // long long v=(long long)floor(exp(log(n)/a))-1;
            int d=1-num[a];
            ans+=v*d;
            for(int b=a;b<=65;b+=a)
            {
                num[b]+=d;
            }
        }
        ans++;
        printf("%lld\n",ans);
    }
    return 0;
}
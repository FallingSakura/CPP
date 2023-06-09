#include<bits/stdc++.h>
#define int long long
const int maxn=5050;
const int mod=1e9+7;
using namespace std;
int n,m,t,num;
int dp[maxn][maxn],a[maxn],vis[maxn];
signed main(){
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++)cin>>a[i],num=max(num,a[i]),vis[a[i]]=1;
    sort(a+1,a+1+m);//小优化
    for(int i=1;i<=m;i++)
        dp[1][a[i]]=1;
    for(int i=2;i<=n;i++)//因为dp[1][k]已经预处理过了,所以从2开始枚举.
    {
        int tot=0,b=0;
        for(int j=1;j<=num;j++)tot+=dp[i-1][j],tot%=mod;
        for(int j=1;j<=min(num,1+t-2);j++)b+=dp[i-1][j],b%=mod;
        for(int j=1;j<=num;j++)
        {
            if(j+t-1<=num)
                b+=dp[i-1][j+t-1],b=(b)%mod;
            if(j-t>=1)
                b-=dp[i-1][j-t],b=(b+mod)%mod;
            if(vis[j])
                dp[i][j]=(dp[i][j]+tot-b+mod)%mod;
            // for(int k=1;k<=num;k++)
            //     if(vis[j]&&abs(j-k)>=t)
            //         dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=num;i++)
        ans=(ans+dp[n][i])%mod;
    cout<<ans<<endl;
    return 0;
}
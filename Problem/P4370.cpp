#include<bits/stdc++.h>
#define int long long
const int mod=1e9+7;
using namespace std;
const int N=1e6+150;
int n,k,ans;
int fac[N],ifac[N];
double lg[N];//阶乘，阶乘的逆元，对数
int dx[]={-1,0,0};
int dy[]={0,-1,1};
map<int,bool> M[N];
struct node{
    int n,m;
    double val;//存下log
    node()
    {
        n=m=0;
    }
    node(int xx,int yy,double v)
    {
        n=xx;
        m=yy;
        val=v;
    }
};
bool operator<(const node &a,const node &b)
{
    return a.val<b.val;
}
priority_queue<node> q;
int C(int x,int y)
{
    if(x<y) return 0;
    return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int ksm(int x,int y)
{
    if(y==1) return x;
    int z=ksm(x,y>>1);
    z=1ll*z*z%mod;
    if(y&1) z=1ll*z*x%mod;
    return z%mod;
}
signed main()
{
    scanf("%lld%lld",&n,&k);
    fac[0]=1;
    ifac[0]=1;
    lg[0]=0.0;
    for(int i=1;i<=n;i++)//预处理
    {
        fac[i]=1ll*fac[i-1]*i%mod;//阶乘
        ifac[i]=ksm(fac[i],mod-2)%mod;//阶乘的逆元
        lg[i]=lg[i-1]+log(i);//阶乘的log
        // cout<<fac[i]<<endl;
    }
    q.push(node(n,n/2,lg[n]-lg[n/2]-lg[n/2]));//第n行
    M[n][n/2]=true;
    while(k--)
    {
        node now=q.top();
        q.pop();
        ans+=C(now.n,now.m)%mod;
        // cout<<C(now.n,now.m)<<endl;
        ans%=mod;
        for(int i=0;i<3;i++)
        {
            int nx=now.n+dx[i];
            int ny=now.m+dy[i];
            if(nx<0||ny<0||M[nx][ny]||ny>nx) continue;
            q.push(node(nx,ny,lg[nx]-lg[ny]-lg[nx-ny]));
            M[nx][ny]=true;
        }
    }
    printf("%lld",ans);
    return 0;
}
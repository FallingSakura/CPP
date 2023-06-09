#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
struct matrix{
    int n,m;
    int z[105][105];
    matrix()
    {
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix M;
matrix operator*(const matrix &a,const matrix &b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for(int i=1;i<=c.n;i++)
        for(int k=1;k<=a.m;k++)
            for(int j=1;j<=c.m;j++)
            {
                c.z[i][j]+=(a.z[i][k] * b.z[k][j]);
                c.z[i][j]%=mod;
            }
    return c;
}
matrix ksm(matrix x,int y)
{
    if(y==1) return x;
    matrix z=ksm(x,y/2);
    z=z*z;
    if(y%2==1) z=z*x;
    return z;
}
signed main()
{
    int n,k;
    scanf("%lld%lld",&n,&k);
    M.n=M.m=n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&M.z[i][j]);
        }
    matrix ans=ksm(M,k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%lld ",ans.z[i][j]);
        puts("");
    }
    return 0;
}
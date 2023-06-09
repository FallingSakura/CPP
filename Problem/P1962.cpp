#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
struct matrix{
    int n,m;
    int z[10][10];
    matrix()
    {
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix A,B;
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
    int n;
    scanf("%lld",&n);
    A.n=1,A.m=2;
    A.z[1][1]=1,A.z[1][2]=0;
    B.n=2,B.m=2;
    B.z[1][1]=1;
    B.z[1][2]=1;
    B.z[2][1]=1;
    B.z[2][2]=0;
    matrix ans=A*ksm(B,n);
    printf("%lld",ans.z[1][2]);
    return 0;
}
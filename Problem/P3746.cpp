#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,r,p;
struct matrix{
    int n,m;
    int z[100][100];
    matrix()
    {
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix D;
matrix f;
matrix operator*(const matrix &a,const matrix &b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for(int i=0;i<=a.n;i++)
        for(int k=0;k<=a.m;k++)
            for(int j=0;j<=b.m;j++)
            {
                c.z[i][j]+=(1ll*a.z[i][k]*b.z[k][j])%p;
                c.z[i][j]=c.z[i][j]%p;
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
int c[100][100];
void pre()
{
    D.n=k,D.m=k,f.n=0,f.m=k;
    for(int i=0;i<=k;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
    }
    for(int r=0;r<k;r++)
        for(int j=0;j<=k;j++)
        {
            int x=(r-j+k)%k;
            if(x-j==k) x=k;
            D.z[x][r]+=c[k][j];
            D.z[x][r]%=p;
        }
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&p,&k,&r);
    pre();
    f.z[0][0]=1;//
    matrix ans=f*ksm(D,n);
    printf("%lld",ans.z[0][r]);//
    return 0;
}
//以上为直接把0作为第一维的做法
//以下为把0转换为k的做法
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,r,p;
struct matrix{
    int n,m;
    int z[100][100];
    matrix()
    {
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix D;
matrix f;
matrix operator*(const matrix &a,const matrix &b)
{
    matrix c;
    c.n=a.n;
    c.m=b.m;
    for(int i=1;i<=a.n;i++)
        for(int k=1;k<=a.m;k++)
            for(int j=1;j<=b.m;j++)
            {
                c.z[i][j]+=(a.z[i][k]*b.z[k][j])%p;
                c.z[i][j]=c.z[i][j]%p;
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
int c[100][100];
void pre()
{
    D.n=k,D.m=k,f.n=1,f.m=k;
    for(int i=0;i<55;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
    }
    for(int r=0;r<k;r++)
        for(int j=0;j<=k;j++)
        {
            int x=(r-j+k)%k;
            D.z[x==0?k:x][r==0?k:r]+=c[k][j];
            D.z[x==0?k:x][r==0?k:r]%=p;
        }
}
signed main()
{
    scanf("%lld%lld%lld%lld",&n,&p,&k,&r);
    pre();
    f.z[1][1]=1;//
    matrix ans=f*ksm(D,n);
    printf("%lld",ans.z[1][r+1]);//
    return 0;
}
*/
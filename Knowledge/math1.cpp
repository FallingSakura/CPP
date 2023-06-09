#include<bits/stdc++.h>
using namespace std;
/*<---------------------->*/
int gcd(int a,int b)
{
    if(b==0) return a;//任何数和0的最大公因数为自身
    return gcd(b,a%b);
}
/*<---------------------->*/
int lcm(int a,int b)
{
    return a * b / gcd(a,b);
}
int ksm(int x,int y,int p)
{
    if(y==0) return 1;
    int z=ksm(x,y/2,p);
    z=1ll*z*z%p;
    if(y&1) z=1ll*z*x%p;
    return z;
}
int kscf(int x,int y,int p)
{
    if(y==0) return 0;
    int z=kscf(x,y/2,p);
    z=(z+z)%p;
    if(y&1) z=(z+x)%p;//判奇
    return z;
}
/*<---------------------->*/
struct matrix{
    int n,m;
    int z[23][23];
    matrix()
    {
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix operator*(const matrix &m1,const matrix &m2)
{
    matrix m3;
    m3.n=m1.n;
    m3.m=m2.m;
    for(int i=1;i<=m3.n;i++)
        for(int k=1;k<=m1.m;k++)
            for(int j=1;j<=m3.m;j++)
                m3.z[i][j]+=m1.z[i][k]*m2.z[k][j];
    return m3;
}
/*<---------------------->*/
matrix jzksm(matrix x,int y)//矩阵快速幂
{
    if(y==1) return x;
    matrix z=jzksm(x,y/2);
    z=z*z;
    if(y&1) z=z*x
    return z;
}
/*<---------------------->*/
/*<---------------------->*/
int a[maxn],f[maxn][maxn];
int main()
{
    /*<---------------------->*/
    int n,p;
    cin>>n>>p;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans%=p;
    }
    /*<---------------------->*/
    int n;
    cin>>n;
    for(int i;i<=n;i++)
        cin>>a[i];
    int ans=a[1];
    for(int i=2;i<=n;i++)
        ans=gcd(ans,a[i]);
    cout<<ans<<endl;
    /*<---------------------->*/
    for(int i=1;i<=y;i++)
        ans=1ll*ans*x%p;
    /*<---------------------->*/
    cin>>n>>p;
    int a=0,b=1;
    for(int i=2;i<=n;i++)
    {
        int c=a+b;
        if(c>=p) c-=p;
        a=b;
        b=c;
    }
    /*<---------------------->*/
    matrix A,B;
    A.n=1;A.m=2;
    A.z[1][1]=1;
    A.z[1][2]=0;
    B.n=2;B.m=2;
    B.z[1][1]=1;
    B.z[1][2]=1;
    B.z[2][1]=1;
    B.z[2][2]=0;
    matrix C=A*jzksm(B,n);
    int ans=C.z[1][2]
    /*<---------------------->*/
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>z[i][j];
    //z[i][j]=0/1;i->j
    f[0][1]=1;
    for(int a=1;a<=k;a++)//走了a步
        for(int d=1;d<=1;d++)
            for(int b=1;b<=n;b++)//走到了b
                for(int c=1;c<=n;c++)//第a-1步在c
                {
                    // if(z[c][b]==1) f[a][b]+=f[a-1][c];
                    f[a][d][b]+=f[a-1][d][c]*z[c][b];
                }
    ans=f[k][1][n];
    return 0;
}
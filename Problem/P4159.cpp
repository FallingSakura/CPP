#include<bits/stdc++.h>
using namespace std;
const int mod=2009;
int nn,t;
struct matrix{
    int n,m;
    int z[185][185];
    matrix()
    {
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix a,F;
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
    matrix zz=ksm(x,y/2);
    zz=zz*zz;
    if(y%2==1) zz=zz*x;
    return zz;
}
signed main()
{
    scanf("%d%d",&nn,&t);
    a.n=10*nn;
    a.m=10*nn;
    for(int i=1;i<=nn;i++)//n=5
    {   
        a.z[i][nn+(i-1)*9+1]=1;
        for(int j=1;j<9;j++)//枚举长度//i=2,j=1
        {
            a.z[nn+(i-1)*9+j][nn+(i-1)*9+j+1]=1;
        }
    }
    char c;
    for(int i=1;i<=nn;i++)
    {
        c=getchar();//读取换行
        for(int j=1;j<=nn;j++)//2->5 cc=1
        {
            c=getchar();
            int cc=c-'0';
            if(cc==0)
            {
                continue;
            }
            if(cc==1) 
            {
                a.z[i][j]=1;
                continue;
            }
            a.z[nn+(i-1)*9+cc-1][j]=1;
        }
    }
    // F0.z[1][1]=1;
    // F0.z[1][2-->n]=0;
    // F1.z[1][1-->n]<----->f[1][1-->n]
    F.n=1;
    F.m=nn;
    F.z[1][1]=1;
    matrix ans=F*ksm(a,t);//F_0乘以t次a变成F_t
    printf("%d",ans.z[1][nn]);
    return 0;
}
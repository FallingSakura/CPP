#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100],y[100];
int lucas(int n,int m)
{
    //1. 转为p进制
    while(n)
    {
        x[0]++;//x[0]代表位数
        x[x[0]]=n%p;
        n=n/p;
    }
    while(m)
    {
        y[0]++;//y[0]代表位数
        y[y[0]]=m%p;
        m=m/p;
    }
    int ans=1;
    for(int i=1;i<=x[0];i++)
        ans=1ll*ans*c[x[i]][y[i]]%p;
}
double logcnm(int n,int m)
{
    return fac[n]-fac[m]-fac[n-m];
}
/*--------------------------*/
void gauss()//double
{
    //a存系数
    for(int i=1;i<=n;i++)//消元
    {
        for(int j=i;j<=n;j++)
        {
            // if(a[j][i]!=0)
            // if(fabs(a[j][i])> 1e-8)//fabs取绝对值，在10^-8以上，就不是0
            if(fabs(a[j][i])> fabs(a[i][i]))//系数更大，就会使误差更小，也就更优，那就换
            {
                for(int k=1;k<=n+1;k++)
                    swap(a[i][k],a[j][k]);//交换方程O(1)

            }
        }
        //要把xi从i+1个方程到第n个方程消掉
        for(int j=i+1;j<=n;j++)
        //把xi从第j个方程开始消掉
        {
            double ratio=a[j][i]/a[i][i];//求应该变的系数
            for(int k=1;k<=n+1;k++)//算上更新常数b
            {
                a[j][k]-=a[i][k]*ratio;//每一个位置都要对应减，长度为n
                //单独减b比较麻烦
            }
        }
    }
    for(int i=n;i>=1;i--)//解方程
    {
        for(int j=i+1;j<=n;j++)
        {
            a[i][n+1]-=a[i][j]*x[j];//把已经回带的未知数移到右边去
        }
        x[i]=a[i][n+1]/a[i][i];//解一元一次方程
    }
}
/*--------------------------*/
void gauss()//int
{
    //a存系数
    for(int i=1;i<=n;i++)//消元
    {
        for(int j=i;j<=n;j++)
        {
            if(a[j][i]!=0)
            // if(fabs(a[j][i])> 1e-8)//fabs取绝对值，在10^-8以上，就不是0
            // if(fabs(a[j][i])> fabs(a[i][i]))//系数更大，就会使误差更小，也就更优，那就换
            {
                for(int k=1;k<=n+1;k++)
                    swap(a[i][k],a[j][k]);//交换方程O(1)
                break;
            }
        }
        //要把xi从i+1个方程到第n个方程消掉
        for(int j=i+1;j<=n;j++)
        //把xi从第j个方程开始消掉
        {
            if(a[j][i]==0) comtinue;
            int l=a[i][i]/gcd(abs(a[i][i]),abs(a[j][i]))*a[j][i];//lcm//可能有负数
            int retioi=l/a[i][i];
            int retioj=l/a[j][i];
            for(int k=1;k<=n+1;k++)//算上更新常数b
            {
                // a[j][k]-=a[i][k]*ratio;//每一个位置都要对应减，长度为n
                a[j][k]=a[j][k]*retioj-a[i][k]*ratioi;
                //单独减b比较麻烦
            }
        }
    }
    for(int i=n;i>=1;i--)//解方程
    {
        for(int j=i+1;j<=n;j++)
        {
            a[i][n+1]-=a[i][j]*x[j];//把已经回带的未知数移到右边去
        }
        x[i]=a[i][n+1]/a[i][i];//解一元一次方程
    }
}
/*--------------------------*/
void gauss()//double
{
    //a存系数
    for(int i=1;i<=n;i++)//消元
    {
        for(int j=i;j<=n;j++)
        {
            // if(a[j][i]!=0)
            // if(fabs(a[j][i])> 1e-8)//fabs取绝对值，在10^-8以上，就不是0
            if(fabs(a[j][i])> fabs(a[i][i]))//系数更大，就会使误差更小，也就更优，那就换
            {
                for(int k=1;k<=n+1;k++)
                    swap(a[i][k],a[j][k]);//交换方程O(1)

            }
        }
        //要把xi从i+1个方程到第n个方程消掉
        for(int j=i+1;j<=n;j++)
        //把xi从第j个方程开始消掉
        {
            double ratio=a[j][i]/a[i][i];//求应该变的系数
            for(int k=1;k<=n+1;k++)//算上更新常数b
            {
                a[j][k]-=a[i][k]*ratio;//每一个位置都要对应减，长度为n
                //单独减b比较麻烦
            }
        }
    }
    for(int i=n;i>=1;i--)//解方程
    {
        for(int j=i+1;j<=n;j++)
        {
            a[i][n+1]-=a[i][j]*x[j];//把已经回带的未知数移到右边去
        }
        x[i]=a[i][n+1]/a[i][i];//解一元一次方程
    }
    //---
    for(int i=n;i>=1;i--)
    {
        for(int j=i-1;j>=1;j--)
        {
            double retio=a[j][i]/a[i][i];
            for(int k=1;k<=n+n;k++)
                a[j][k]-=a[i][k]*retio;
        }
    }
    for (int i=1;i<=n;i++)
	{
		double k=a[i][i];
		for (int j=1;j<=n+n;j++)
			a[i][j] /= k;
	}
    //a[1~n][n+1~2n]
}
int main()
{
    for(int i=0;i<=n;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)//从i个东西最多选i个
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];//组合
        }
    }
    /*--------------------------*/
    for(int i=0;i<=n;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)//从i个东西最多选i个
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;//组合
        }
    }
    //算完求一下有多少个%p=0的就行了
    /*--------------------------*/
    fac[0]=1;//0!
    for(int i=1;i<=1000000;i++)
        fac[i]=1ll*fac[i-1]*i%p;
    C(n,m)=1ll*fac[n]*ksm(fac[m],p-2,p)%p*ksm(fac[n-m],p-2,p)%p;
    /*--------------------------*/
    for(int i=1;i<=m;i++)
    {
        fm[i]=i;
        fm[i]=n-i+1;
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
        {
            int g=gcd(fz[i],fm[j]);
            fz[i]/=g;
            fm[i]/=g;//约分
        }
    int ans=1;
    for(int i=1;i<=m;i++)
        ans*=1ll*fz[i]%p;
    /*--------------------------*/
    cin>>n>>m>>p;
    for(int i=0;i<=p;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
        }
    }
    /*--------------------------*/
    //fac[i]=log i!//处理log
    fac[0]=0;
    for(int i=1;i<=1000000;i++)
    {
        fac[i]=fac[i-1]+log(i);
    }
    //比较logC（1）和logC（2）就可以了
    /*--------------------------*/
    cin>>n;
    for(int a=2;a<=64;a++)
    {
        num[a]=0;//代表x的a次方这种形式的数被算了几次，它应该为1

    }
    for(int a=2;a<=64;a++)
    {
        //算x^a这种形式的数有多少个
        //pow要下取整，不能四舍五入
        long long v=pow(n,1.0/a)-1;//减去1的a次方这个方案数，因为1^a会被算63次//pow(x,y)计算x的y次方-->开a次方根，减去1次方
        //把1去掉
        int d=1-num[a];//代表这个数还要算几次//3,2,1,0,-1,-2...
        //d*v就是对答案的贡献,通过算了多少次就可以知道容斥系数
        ans+=v*d;
        for(int b=a;b<=64;b+=a)
        {
            //顺便更新一下num[a]
            num[b]+=d;//b被算了这么多次，就把所有a的倍数次幂也都加上，表示a的倍数次幂现在被提前算了多少次
        }
    }
    ans++;//因为一开始就没算1，所以要加上1
    /*--------------------------*/
    double a[][];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
        // cin>>b[i];
        cin>>a[i][n+1];//存b
    }
    /*--------------------------*/
    int a[][];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
        // cin>>b[i];
        cin>>a[i][n+1];//存b
    }
    /*--------------------------*/
    double a[][];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
        // cin>>b[i];
        cin>>a[i][n+1];//存b
    }
}
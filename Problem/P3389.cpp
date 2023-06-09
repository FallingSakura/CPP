#include<bits/stdc++.h>
#define db double
using namespace std;
int n;
db a[105][105];
db x[105];
bool gauss()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(fabs(a[j][i])>fabs(a[i][i]))
            {
                for(int k=1;k<=n+1;k++)
                    swap(a[i][k],a[j][k]);//交换方程
            }
        }
        for(int j=i+1;j<=n;j++)
        {
            db ratio=a[j][i]/a[i][i];
            for(int k=1;k<=n+1;k++)
            {
                a[j][k]-=a[i][k]*ratio;
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            a[i][n+1]-=a[i][j]*x[j];
        }
        x[i]=a[i][n+1]/a[i][i];
        if(x[i]==0) return false;//如果解出来某一项为0，那么就无解
    }
    return true;
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            scanf("%lf",&a[i][j]);
        }
    }
    bool o=gauss();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            printf("%d",a[i][j]);
        }
    }
    if(!o) printf("No Solution");
    else
    {
        for(int i=1;i<=n;i++)
            printf("%.2lf\n",x[i]);
    }
    
}
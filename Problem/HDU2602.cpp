#include<bits/stdc++.h>
using namespace std;
int t;
int a[2000],f[2000][2000],w[2000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        memset(w,0,sizeof(w));
        int n,v;
        scanf("%d%d",&n,&v);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<=v;j++)
            {
                if(a[i]>j) f[i][j]=f[i-1][j];
                else f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+w[i]);
            }
        printf("%d\n",f[n][v]);
    }
    return 0;
}
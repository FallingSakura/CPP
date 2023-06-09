#include<bits/stdc++.h>
using namespace std;
const int Y=0x3f3f3f;
const int N=205;
int f[N][N],bj[N],n,m,Q,t[N];
int main()
{
    scanf("%d%d",&n,&m);
    memset(f,0x3f3f3f,sizeof(f));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        f[a][b]=f[b][a]=c;
    }
    scanf("%d",&Q);
    while(Q--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        for(int k=0;k<n;k++)
        {
            if(t[k]<=w&&!bj[k])
            {
                bj[k]=1;
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        if(f[i][j]>f[i][k]+f[k][j])
                            f[i][j]=f[i][k]+f[k][j];
            }
        }
        if(t[u]<=w&&t[v]<=w&&f[u][v]<Y) printf("%d\n",f[u][v]);
        else printf("-1\n");
    }
    return 0;
}
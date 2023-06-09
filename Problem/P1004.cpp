#include<bits/stdc++.h>
using namespace std;
struct point{
    int x;
    int y;
    int w;
}p[1000];
int n,cnt;
int m[100][100],f[20][20][20][20];
int main()
{
    scanf("%d",&n);
    while(true)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!a&&!b&&!c)
            break;
        p[++cnt].x=a;
        p[cnt].y=b;
        p[cnt].w=c;
    }
    for(int i=1;i<=cnt;i++)
        m[p[i].x][p[i].y]=p[i].w;
    for(int i=1;i<=n;i++)//四维DP
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=n;l++)
                {
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+m[i][j]+m[k][l];
                    if(i==k&&l==j)f[i][j][k][l]-=m[i][j];//走重复了
                }
    cout<<f[n][n][n][n];
    return 0;
}
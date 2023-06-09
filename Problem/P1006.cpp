#include<bits/stdc++.h>
using namespace std;
int n,o;
int m[100][100],f[60][60][60][60];
int main()
{
    scanf("%d%d",&n,&o);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=o;j++)
            scanf("%d",&m[i][j]);
    for(int i=1;i<=n;i++)//四维DP
        for(int j=1;j<=o;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=o;l++)
                {
                    f[i][j][k][l]=max(max(f[i-1][j][k-1][l],f[i][j-1][k-1][l]),max(f[i-1][j][k][l-1],f[i][j-1][k][l-1]))+m[i][j]+m[k][l];
                    if(i==k&&l==j)f[i][j][k][l]-=m[i][j];//走重复了
                }
    cout<<f[n][o][n][o];
    return 0;
}
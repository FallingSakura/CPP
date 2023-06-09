#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int f[105][105][3];
bool same()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j][0]!=f[i][m-j+1][0]||f[i][j][1]!=f[i][m-j+1][1]||f[i][j][2]!=f[i][m-j+1][2])
                return false;
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(d>255) d%=256;
        if(f[a][b][c-1]+d>255)
            f[a][b][c-1]=(f[a][b][c-1]+d)%256;
        else f[a][b][c-1]+=d;
        if(same()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long f[30][30];
int ctrl[30][30],n,m,hx,hy;
int d[9][2]={{0,0},{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
signed main()
{
    cin>>n>>m>>hx>>hy;
    for(int i=0;i<9;i++)
    {
        int tmpx=hx+d[i][0];
        int tmpy=hy+d[i][1];
        if(tmpx>=0&&tmpx<=n&&tmpy>=0&&tmpy<=m)
            ctrl[tmpx][tmpy]=1;
    }
    f[0][0]=1-ctrl[0][0];//防止马守你出生点
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(ctrl[i][j]) continue;
            if(i) f[i][j]+=f[i-1][j];
            if(j) f[i][j]+=f[i][j-1];
        }
    cout<<f[n][m];
    return 0;
}
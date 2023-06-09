#include<bits/stdc++.h>
using namespace std;
int n,m,xx,yy;
struct horse{
    int x,y;
};
queue<horse> Q;
int ans[400][400];
int walk[8][2]={ {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };
int main()
{
    cin>>n>>m>>xx>>yy;
    memset(ans,-1,sizeof(ans));
    horse tmp={xx,yy};
    Q.push(tmp);
    ans[xx][yy]=0;
    while(!Q.empty())
    {
        horse u=Q.front();
        int ux=u.x,uy=u.y;
        Q.pop();
        for(int k=0;k<8;k++)
        {
            int nx=ux+walk[k][0];
            int ny=uy+walk[k][1];
            int d=ans[ux][uy];
            if(nx<1||nx>n||ny<1||ny>m||ans[nx][ny]!=-1)
                continue;
            ans[nx][ny]=d+1;
            horse tmp={nx,ny};
            Q.push(tmp);
        }
    }
    for(int i=1;i<=n;i++,puts(""))
    {
        for(int j=1;j<=m;j++)
            printf("%-5d",ans[i][j]);
    }
    return 0;
}
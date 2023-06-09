#include<bits/stdc++.h>
using namespace std;
int t,k;
int f[2005][2005],ans[2005][2005];
inline int read()
{
	int x=0,y=1;//x是什么，y是正负 
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int main()
{
    t=read();
    k=read();
    for(int i=0;i<=2000;i++)
        {
            f[i][0]=1;
            for(int j=1;j<=i;j++)
            {
                f[i][j]=(f[i-1][j-1]+f[i-1][j])%k;
                ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
                if(f[i][j]==0) ans[i][j]++;
            }
            ans[i][i+1]=ans[i][i];
        }
    for(int l=1;l<=t;l++)
    {
        int n,m;
        n=read();
        m=read();
        if(m<=n)
            printf("%d\n",ans[n][m]);
        else printf("%d\n",ans[n][n]);
    }
    return 0;
}
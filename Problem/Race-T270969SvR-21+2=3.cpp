#include<bits/stdc++.h>
using namespace std;
int a[1000];
const int N=100005,M=200005;
int frt[N],nxt[M],to[M],val[M],vl[N],cnt;
int bj[N];
void add_edge(int u,int v)
{
	cnt++;
	nxt[cnt]=frt[u];
	frt[u]=cnt;
	to[cnt]=v;
	return;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int o=1;o<=T;o++)
    {
        int ans=0;
        int l=0,r=0;
        for(int i=1;i<=9;i++)
        {
            scanf("%d",&a[i]);
            for(int j=1;j<=a[i];j++)
            {
                add_edge(l,r);
            }
            if(r<2)
                r++;
            else if(l<2)
            {
                l++;
                if(r==2)
                    r=0;
            }
        }
        for(int i=0;i<=2;i++)
        {
           for(int j=frt[i];j;j=nxt[j])
            {
                for(int k=j;k;k=nxt[k])
                {
                    if(to[j]+to[k]==3&&bj[j]!=k&&bj[k]!=j)
                    {
                        ans++;
                        bj[j]=k;
                        bj[k]=j;
                    }
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
int h[N],e[N],nex[N],cnt;
int que[N],d[N];
void add(int a,int b)//他是从0~m-1
{
    e[++cnt]=b;//end
    nex[cnt]=h[a];
    h[a]=cnt;
}
bool topsort()
{
    int hh=1,tt=0;
    for(int l=1;l<=n;l++)
        if(!d[l])
            que[++tt]=l;
        while(hh<=tt)
        {
            int t=que[hh++];//取出队首
            for(int i=h[t];i!=-1;i=nex[i])
            {
                int j=e[i];
                d[j]--;
                if(d[j]==0)
                    que[++tt]=j;
            }
        }
    return tt==n;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        d[b]++;
    }
    if(topsort())
    {
        for(int i=1;i<=n;i++)
            printf("%d ",que[i]);
        puts("");
    }
    else
        cout<<-1<<endl;
    return 0;
}
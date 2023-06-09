#include<bits/stdc++.h>
using namespace std;
struct edge{
    int nxt,to;
}e[1000];
struct node{
    int u,v;
}p[1000];
int cnt,cnnt,f;
int head[1000],d[1000],q[1000];
void add(int u,int v)
{
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
int n,m;
int l,r;
int topsort()
{
    int temp;
    int f=0;
    l=1,r=0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            q[++r]=i;
            temp++;
        }
    }
    if(temp>1) f=1;
    while(l<=r)
    {
        temp=0;
        int u=q[l++];
        for(int j=head[u];j;j=e[j].nxt)
        {
            d[e[j].to]--;
            if(d[e[j].to]==0)
            {
                q[++r]=e[j].to;
                temp++;
            }
        }
        if(temp>1) f=1;
    }
    if(r!=n) return 3;
    else
        if(f==1)
            return 2;
    else return 1;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        p[i].u=s[0]-'A'+1;
        p[i].v=s[2]-'A'+1;
    }
    for(int i=1;i<=m;i++)
    {
        add(p[i].u,p[i].v);
        memset(d,0,sizeof(d));
        for(int j=1;j<=i;j++) d[p[j].v]++;
        int opt=topsort();
        if(opt==1)
        {
            printf("Sorted sequence determined after %d relations: ",cnt);
            for(int j=1;j<=n;j++)
            {
                printf("%c",(char)(q[j]+'A'-1));
            }
            printf(".");
            return 0;
        }
        if(opt==2) continue;
        if(opt==3)
        {
            printf("Inconsistency found after %d relations.",cnt);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.");
    return 0;
}
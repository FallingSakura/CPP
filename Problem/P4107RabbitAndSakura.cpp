#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,m,c[maxn];
int cost[maxn],ans;
struct node{
    int to,next;
}ed[maxn];
int first[maxn],cnt,temp[maxn];
void add(int u,int v)
{
    ed[++cnt].to=v;
    ed[cnt].next=first[u];
    first[u]=cnt;
}
void dfs(int x)
{
    for(int i=first[x];i ;i=ed[i].next) 
    {
        int v=ed[i].to;
        dfs(v);
    }
    int top=0;
    for(int i=first[x];i;i=ed[i].next)
    {
        int v=ed[i].to;
        temp[++top]=cost[v];
    }
    sort(temp+1,temp+top+1);
    for(int i=1;i<=top;i++)
    {
        if(cost[x]+temp[i]-1<=m)
        {
            cost[x]+=temp[i]-1;
            ans++;
        }
        else
            break;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(int i=0;i<n;i++)
    {
        int lp;
        scanf("%d",&lp);
        cost[i]=lp+c[i];
        for(int j=1;j<=lp;j++)
        {
            int s;
            scanf("%d",&s);
            add(i,s);
        }
    }
    dfs(0);
    printf("%d",ans);
}

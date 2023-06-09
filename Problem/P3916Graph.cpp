#include<bits/stdc++.h>
using namespace std;
const int N =100005;
int ans[N];
int n,m;
struct Edge{
    int to,nxt;
}e[N<<1];
int head[N],cnt=0;
void add(int u,int v)
{
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
void dfs(int u,int fa,int minn)
{
    if(ans[u]) return;
    ans[u]=minn;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==fa) continue;
        if(ans[v]) continue;
        dfs(v,u,minn);
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        add(v,u);
    }
    for(int i=n;i>=1;i--)
        dfs(i,0,i);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
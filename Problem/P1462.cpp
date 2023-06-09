#include<bits/stdc++.h>
using namespace std;
const int N=50005,M=1000005;
int n,m,b;
int f[N],fir[N],cnt,dist[N],righ[N];
struct edge{
    int next,to,w;
}e[M];
const int MAX=1e9;
void add(int u,int v,int w)
{
    e[++cnt].next=fir[u];
    e[cnt].to=v;
    e[cnt].w=w;
    fir[u]=cnt;
}
struct node{
    int p,d;
    node(){}
    node(int a,int b){p=a;d=b;}
};
bool operator<(const node &a,const node &b)
{
    return a.d>b.d;
}
priority_queue<node>q;
int dijksta(int x)
{
    if(x<f[1]) return 0;
    for(int i=1;i<=n;i++)
        dist[i]=1e9;
    memset(righ,0,sizeof(righ));
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
        q.push(node(i,dist[i]));
    }
    for(int i=1;i<=n;i++)
    {
        while(righ[q.top().p]) q.pop();
        node now=q.top();
        int p=now.p;
        righ[p]=1;
        q.pop();
        for(int j=fir[p];j;j=e[j].next)
        {  
            int v=e[j].to;
            if(f[v]>x) continue;
            int d=e[j].w+dist[p];
            if(d<dist[v])
            {
                dist[v]=d;
                
                q.push(node(v,d));
            }
        }
    }
    if(dist[n]<=b) return 1;
    return 0;
}
int erfen()
{
    int l=1,r=MAX,mid=(l+r)>>1;
    int c;
    while(l<=r)
    {
        c=dijksta(mid);
        if(c!=0)
        {
            r=mid-1;
            mid=(l+r)>>1;
        }
        else
        {
            l=mid+1;
            mid=(l+r)>>1;
        }
    }
    return l;
}
int main()
{
    scanf("%d%d%d",&n,&m,&b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    if(dijksta(MAX)==0)
    {
        cout<<"AFK"<<endl;
        return 0;
    }
    cout<<erfen()<<endl;
}
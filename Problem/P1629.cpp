#include<bits/stdc++.h>
using namespace std;
const int N=400005;
const long long MAX=1e14;
int n,m,cnt;
int fir[N],righ[N];
long long dist[N];
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
struct edge{
    int next,to,w;
}e[N];
struct point{
    int p;
    long long d;
    point(){}
    point(int a,long long b):p(a),d(b){}
};
void add(int u,int v,int w)
{
    e[++cnt].next=fir[u];
    e[cnt].to=v;
    e[cnt].w=w;
    fir[u]=cnt;
}
priority_queue<point>q;
bool operator<(const point &a,const point &b)
{
    return a.d>b.d;
}
void dijkstra(int s)
{
    for(int i=1;i<=n<<1;i++)
    {
        dist[i]=MAX;
    }
    dist[s]=0;
    q.push(point(s,dist[s]));
    while(!q.empty()) 
    {
        // while(righ[q.top().p]) q.pop();
        point now=q.top();
        int p=now.p;
        q.pop();
        // righ[p]=1;
        for(int j=fir[p];j;j=e[j].next)
        {
            int v=e[j].to;
            int d=e[j].w+dist[p];
            if(dist[v]>d)
            {
                dist[v]=d;
                q.push(point(v,d));
            }
        }
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        a=read();
        b=read();
        c=read();
        add(a,b,c);
        add(b+n,a+n,c);
    }
    long long ans=0;
    dijkstra(1);
    for(int i=2;i<=n;i++)
    {
        ans+=dist[i];
    }
    dijkstra(1+n);
    for(int i=2+n;i<=n<<1;i++)
    {
        ans+=dist[i];
    }
    printf("%lld\n",ans);
    return 0;
}
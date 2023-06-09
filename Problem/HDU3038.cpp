#include<bits/stdc++.h>//HDU交G++
using namespace std;
const int N=200010;
int s[N];//集合
int d[N];//权值，代表当前节点到根节点的距离,以集合的左端点为根
int ans;
void init_set()
{
    for(int i=0;i<=N;i++)
    {
        s[i]=i;
        d[i]=0;
    }
}
int find_set(int x)
{
    if(x!=s[x])
    {
        int t=s[x];
        s[x]=find_set(s[x]);
        d[x]+=d[t];
    }
    return s[x];
}
void merge_set(int a,int b,int v)
{
    int roota=find_set(a),rootb=find_set(b);
    if(roota==rootb)
    {
        if(d[a]-d[b]!=v)
            ans++;
    }
    else
    {
        s[roota]=rootb;
        d[roota]=d[b]-d[a]+v;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init_set();
        ans=0;
        while(m--)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            a--;//区间合并原理，因为[1,2]+[3,4]=[1,4]，所以要把左端点-1这样才能参加计算，不然要算端点
            //所以就是(0,2]+(2,4]=(0,4]
            merge_set(a,b,v);
        }
        printf("%d\n",ans);
    }
    return 0;
}
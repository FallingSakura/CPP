#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int s[N];
void init()
{
    for(int i=1;i<=N;i++)
    {
        s[i]=i;
    }
}
int find(int x)
{
    return x==s[x]?s[x]:find(s[x]);
}
void merge(int a,int b)
{
    a=find(a),b=find(b);
    if(a!=b) s[a]=s[b];
}
int main()
{
    int t,n,m,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            merge(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]==i) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
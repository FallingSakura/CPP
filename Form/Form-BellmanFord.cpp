#include<bits/stdc++.h>
using namespace std;
#define maxn 10000007
int n,dist[maxn],m,first[maxn];
int s[maxn],e[maxn],d[maxn];
int main()
{
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&s[i],&e[i],&d[i]);//起点，终点，长度
    }
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;//起点距离
    for(int i=1;i<n;i++)//最多n-1条边,最多松弛n-1次，因为如果倒着来的话，所有点的dist都未知，每次只能更新一个点，因此每轮会至少松弛一个点
        for(int j=1;j<=m;j++)
        {
            dist[e[j]]=min(dist[e[j]],dist[s[j]]+d[j]);
        }
    return 0;
}
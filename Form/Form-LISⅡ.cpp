#include<bits/stdc++.h>
using namespace std;

int z[10000],f[10000],a[10000];
int cnt=0;
int main()
{
    for(int i=1;i<=n;i++)
    f[i]=1;
    erfen();//直接用二分优化
    // for(int j=1;j<=cnt;j++)
    //     if(a[z[j]]<a[i]) f[i]=max(f[i],j+1);
    if(f[i]>cnt)//第一次算出这个长度相当于长度为2，之前的长度均为1
        z[++cnt]=i;//z存的是f[i]下标
    else if(a[i]<a[z[f[i]]]) z[f[i]]=i;//有两个长度为2，但一个是以3结尾，一个是以6结尾，那肯定要以3结尾的
}
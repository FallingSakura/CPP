#include<bits/stdc++.h>
using namespace std;
int f[10000];//f[i]代表i必选且i为最后一个数得到的最长
int g[10000];//g[i]代表最长的长度的方案数
int pre[10000];//上一个状态是从哪里走过来的
int main()
{
    for(int i=1;i<=n;i++)
    {
        f[i]=1;//至少为1
        g[i]=1;//自己是一个方案
        pre[i]=0;//前面没东西
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
            {
                int l=f[j]+1;
                if(l>f[i])
                {
                    f[i]=l;//更新最长长度,一定会进入下一分支
                    g[i]=0;//每周j的方案后面加上一个i长度不变
                    pre[i]=j;//更新i这个位置的状态是从j更新的
                }
                if(l==f[i])
                {
                    g[i]+=g[j];//新的方案数就等于原来的方案数加上新的方案数
                }
            }
    }
    int p,cnt=0;//从p开始走
    do
    {
        z[++cnt]=p;
        p=pre[p];
    }while(p!=0);
    reverse(z+1,z+cnt+1);
    return 0;
}
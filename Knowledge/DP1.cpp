z[233];
f[233];
a[233];
cnt=0;
for(int i=1;i<=n;i++)
{
    f[i]=1;
    for(int j=1;j<=cnt;j++)//把循环变成二分就可以优化为nlogn
    {
        if(a[z[j]]<a[i])//z[j]为f[j]=j的数在a中的下标
            f[i]=max(f[i],j+1);
    }
    if(f[i]>cnt)
    {
        cnt++;
        z[cnt]=i;
    }
    else
    {
        if(a[i]<a[z[f[i]]])
            z[f[i]]=i;//存下标
        //如果需要方案，就记录一下从哪转移过来的
    }
    
}
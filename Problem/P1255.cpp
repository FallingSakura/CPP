#include<bits/stdc++.h>
using namespace std;
struct Bigint
{
    int len,a[2000];
    Bigint(int x=0)
    {
        memset(a,0,sizeof(a));
        for(len=1;x;len++)
        {
            a[len]=x%10;
            x/=10;
        }
        len--;
    }
    int &operator[] (int i)//这里加&是为了在外面可以使用这样定义的[]
    {
        return a[i];
    }
    void flatten(int L)
    {
        len=L;
        for(int i=1;i<=len;i++)
        {
            a[i+1]+=a[i]/10,a[i]%=10;
        }
        while(!a[len])
            len--;
    }
    void print()
    {
        for(int i=max(1,len);i>=1;i--)
            printf("%d",a[i]);
    }
};
Bigint operator+(Bigint a,Bigint b)
{
    Bigint c;
    int len=max(a.len,b.len);
    for(int i=1;i<=len;i++)
        c[i]+=a[i]+b[i];
    c.flatten(len+1);//答案不超过len+1位
    return c;
}
Bigint operator*(Bigint a,int b)
{
    Bigint c;
    int len=a.len;
    for(int i=1;i<=len;i++)
    {
        c[i]=a[i]*b;
    }
    c.flatten(len+11);//int最长10位
    return c;
}
signed main()
{
    int n;
    cin>>n;
    Bigint f[5010];
    f[1]=Bigint(1);
    f[2]=Bigint(2);
    for(int i=3;i<=n;i++)
    {
        f[i]=f[i-2]+f[i-1];
    }
    f[n].print();
    return 0;
}
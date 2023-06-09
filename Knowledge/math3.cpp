#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*-------------------*/
    for(int a=2;a<=n;a++)
        for(int b=a+a;b<=n;n+=a)//枚举a的所有倍数
            not_prime[b]=true;
    for(int a=2;a<=n;a++)
        if(not_prime[a]==false) 
            prime[++cnt]=a;
    /*-------------------*/
    for(int a=2;a<=n;a++)
        if(not_prime[a]==flase)
            for(int b=a+a;b<=n;n+=a)//枚举a的所有倍数
                not_prime[b]=true;
    /*-------------------*/
    for(int i=2;i<=n;i++)//先枚举倍数
    {
        if(not_prime[i]==false)//一定是质数吗？有没有可能只是没被标为true
        {
            cnt++;
            prime[cnt]=i;//存进质数表
        }
        for(int j=1;j<=cnt;j++)
        {
            int x=prime[j]*i;//筛掉第j个质数的i倍
            if(x>n) //质数表是从小往大枚举的，这是第一个大于n的
            {
                break;
            }
            not_prime[x]=true;
            if(i%prime[j]==0) break; //O（n）//保证每个数只被最小的质因子筛掉
        }
    }
    /*-------------------*/
    phi[1]=1;
    for(int i=2;i<=n;i++)//先枚举倍数
    {
        if(not_prime[i]==false)//一定是质数吗？有没有可能只是没被标为 true
        {
            cnt++;
            prime[cnt]=i;//存进质数表
            phi[i]=i-1;//剩下的就是和数
        }
        for(int j=1;j<=cnt;j++)
        {
            int x=prime[j]*i;//筛掉第j个质数的i倍
            if(x>n) //质数表是从小往大枚举的，这是第一个大于n的
            {
                break;
            }
            not_prime[x]=true;
            phi[x]=phi[prime[j]]*phi[i];//函数性质//假设它们全是互质的
            if(i%prime[j]==0)
            {
                phi[x]=prime[j]*phi[i];//代入方程后发现后半部分就是phi[i]
                break; //O（n）//保证每个数只被最小的质因子筛掉
            }
        }
    }
    
}
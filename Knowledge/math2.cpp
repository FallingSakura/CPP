#include<bits/stdc++.h>
using namespace std;
/*-------------------*/
int get_phi(int n)
{
    int phi =n;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
        {
            phi=phi/i*(i-1);
            while(n%i==0)
            {
                n=n/i;//把i的几次方全部去掉
            }
        }
    if(n!=1)//最后一个质数是n，如果是很多次方，循环不会停止
        phi=phi/n*(n-1);
    return phi;
}
/*-------------------*/
bool mb(int n,int a)//检查是否符合定理中的一个，现在要求d和r
{
    int d=n-1,r=0;//不断拿d除以2
    while(n-d%2==0)
        d=d/2,r++;
    int x=ksm(a,d,n);
    if(x==1) return true;
    for(int i=0;i<r;i++)
    {
        //a的d次方已经算过了，每加一次
        if(x==n-1) return true;
        x=1ll*x*x%n;//不然就平方一下
    }
    return false;
}
bool is_prime(int n)
{
    if(n<2) return false;
    for(int i=1;i<=23;i++)//正常20次是足够的
    {
        int a=rand()%(n-1)+1;//随机检查 1~n-1
        if(!mb(n,a)) return false;
    }
}
/*-------------------*/
int prime_list[]={2,3,5,7,13,23,37,73};
bool is_prime(int n)
{
    if(n<2) return false;
    for(int i=0;i<=8;i++)//正常20次是足够的
    {
        if(n==prime_list[i])  return true;
        if(n%prime_list[i]==0) return false;
        if(!mb(n,prime_list[i]%n)) return flase;//满足条件a<n
        
    }
}
/*-------------------*/
int exgcd(int a,int b,int &x,int &y)//g=gcd(a,b),xy通过取地址
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;//gcd
    }
    int xp,yp;
    int g=exgccd(b,a%b,xp,yp);//最大公因数
    // 返回后一定满足xp*b+yp*a%b=g
    // xp*b+yp*(a-b*(a/b))=g
    // xp*b+yp*a-yp*b*(a/b)=g
    // yp*a+(xp-yp*(a/b))*b=g
    x=yp;
    y=xp-yp*(a/b);//每层的xy是变的，g一直都是a b的gcd
    return g;
}
/*-------------------*/
//x%p=a
void solve(int p1,int a1,int p2,int a2,int &p,int &a)//要返回两个,就加两个取地址
{
    if(p1<p2) swap(p1,p2),swap(a1,a2);
    int x=a1;
    int g=gcd(p1,p2);
    int l=p1/g*p2;//lcm
    while(x%p2!=a2&&x<=l)//第一次超过最小公倍数就开始从a1开始循环
    {
        x+=p1;
    }
    if(x>l) p=-1,a=-1;//标记无解
    else p=l,a=x;//?
}
void solve(int p1,int a1,int p2,int a2,int &p,int &a)
//x%p1=a1
//x%p2=a2
//x%p=a
//扩展中国剩余定理，不要求p互质
{
    //x=k1*p1+a1=k2*p2+a2////////<-----
    //k1*p1-k2*p2=a2-a1
    int g,k1,k2;
    g=exgcd(p1,p2,k1,k2);
    //k1*p1+k2*p2=g
    k2=-k2;
    //k1*p1-k2*p2=g
    //看下a2-a1是g的多少倍
    if((a2-a1)%g!=0)//因为左边是若干倍的g()
    {
        p=-1;//无解
        a=-1;
    }
    else{//有解
        int k=(a2-a1)/g;
        k1=k1*k;//可能乘炸long long，可以提前对p取模，可以采取快速乘法边乘边模
        k2=k2*k;
        int x=k1*p1+a1;//解出x
        p=p1/g*p2;//LCM
        a=(x%p+p)%p;
    }
    
}
/*--------------------------*/
void solve(int a,int b,int p)
{
    int v=1;//a的零次
    for(int x=0;x<p-1;x++)
    {
        if(v==b) return x;
        v=1ll*v*a%p;
    }
    return -1;
}

int solve(int a,int b,int p)
{
    int s=sqrt(p);
    int v=1;
    set<int> se;
    for(int i=0;i<s;i++)
    {
        se.insert(v);//把第一行全部存下来了
        v=1ll*v*a%p;
        //STL有一个东西叫set，可以存一堆数，查找一个数在这堆数中是否出现过
    }
    for(int i=0;i*s<=p;i++)//看答案是否在第i行里面,第一行是第0行//超过p次方就会开始循环
    {
        //看b乘以a的-is次方是否在第零行出现——逆元
        int c=1ll*b*ksm(ksm(a,i*s,p),p-2,p)%p;//快速幂
        if(se.count(c)!=0)//出现次数 0/1
        {
            //答案在第i行,暴力一遍
            int v=ksm(a,i*s,p);
            for(int j=i*s;;;j++)//一定会找到答案
            {
                if(v==b) return j;//找答案
                v=1ll*v*a%p;
            }
        }
    }
}
int fac[maxn],ifac[maxn];//阶乘,i的阶乘的逆元
int inv[maxn];i的逆元
int main()
{
    /*-------------------*/
    for(int a=2;a*a<=x;a++)
        if(x%a==0)//第一个质因子,每次进来都一定是一个质因子
        {
            cnt++;
            prime[cnt]=a;
            while(x%a==0)
            {
                num[cnt]++;
                x/=a;
            }
        }
    if(x!=1)
    {
        cnt++;
        prime[cnt]=x;
        num[cnt]=1
    }
    /*-------------------*/
    fac[0]=1;
    for(int i=1;i<=n;i++)//1
    {
        fac[i]=1ll*fac[i-1]*i%p;
    }
    ifac[n]=ksm(fac[n],p-2,p);//算n的阶乘的逆元
    for(int i=n-1;i>=0;i--)//2
    {
        ifac[i]=1ll*ifac[i+1]*(i+1)%p;
    }
    for(int i=1;i<=n;i++)//3
    {
        inv[i]=fac[i-1]*ifac[i]%p;//除以i的阶乘也就是乘以i的阶乘的逆元
    }
    /*-------------------*/
    cin>>n>>p;
    inv[1]=1;
    for(int i=2;i<=n;i++)
    {
        int k=p/i;//除数
        int r=p%i;//余数
        inv[i]=1ll*(p-k)*inv[r]%p;//加上一个p防止对负数取模
    }
    /*-------------------*/
    //n-=d*^r
    //1<= a <n
    //1.a^d%n 1
}
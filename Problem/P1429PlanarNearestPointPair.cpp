#include<bits/stdc++.h>
using namespace std;
#define MAX 2<<20
const int maxn=1000001;
//double min(double a, double b) { return a < b ? a : b; }
struct point
{
    double x,y;
};
bool cmp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;
}
bool ccmp(point v,point k)
{
    return v.y<k.y;
}
point a[maxn],L[maxn],R[maxn];
double dis3=MAX;
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));//小心乘号
}
double solve(int l,int r)
//代表点a【l】~a【r】中最近点对的距离
//ans=solve(1,n)
{
    double d=MAX;
    if(l==r)
        return d;
    if(l+1==r)
        return dist(a[l],a[r]);
    double dis1,dis2,dis3=MAX;
    int m=(l+r)/2;
    //dis1表示两个点都在左边时的最短距离
    //dis2表示两个点都在右边时的最短距离
    //dis3表示一个点在左边一个点在右边的最短距离
    dis1=solve(l,m);
    dis2=solve(m+1,r);
    d=min(dis1,dis2);
 //   cout<<dis1<<endl<<dis2<<endl<<d<<endl;
    //求dis3
    //L[]表示左半边可能更新答案的点//x坐标符合要求
    //R[]表示右半边可能更新答案的点
    int L_size=0,R_size=0;
    for(int i=m;i>=l;i--)
    {
        if(a[m].x-a[i].x>d)
            break;
        L[L_size++]=a[i];
    }
    for(int i=m+1;i<=r;i++)
    {
        if(a[i].x-a[m].x>d)
            break;
        R[R_size++]=a[i];
    }
    //next
    sort(L,L+L_size,ccmp);//把L数组按照y坐标排序 
    sort(R,R+R_size,ccmp);//把R数组按照y坐标排序
    int j=0;
    double tmp;
    for(int i=0;i<L_size;i++)
    {
        while(j<R_size&&L[i].y-R[j].y>d)//过滤出不在范围内的点
            j++;
       // cout<<R_size<<endl;
        for(int k=j;k<R_size;k++)
        {
            if(R[k].y-L[i].y>d)
                break;
            //next 
            //计算L[i]和R[k]的距离，更新dis3
           // cout<<L[i].x<<' '<<L[i].y<<' '<<R[k].x<<' '<<R[k].y<<' '<<endl;
            tmp=dist(L[i],R[k]);
          //  cout<<tmp<<endl;
            dis3=min(dis3,tmp);
        }
    } 
  //  cout<<dis3<<endl;
    return min(d,dis3);
}
int main()
{
     int n;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);
 //       cout<<a[i].x<<' '<<a[i].y<<endl;
    }
    sort(a,a+n,cmp);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a[i].x<<' '<<a[i].y<<endl;
    // }排序无问题
    printf("%.4lf\n",solve(1,n));
}
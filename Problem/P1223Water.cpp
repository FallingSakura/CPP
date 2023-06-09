#include<bits/stdc++.h>
using namespace std;
struct water{
    int num,ti;
}t[10100];
bool cmp(water a,water b)
{
    if(a.ti!=b.ti)
        return a.ti<b.ti;
    return a.num<b.num;
}

double ans;
int main()
{
    // freopen("E:\\P1223_3.in","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t[i].ti);
        t[i].num=i;
    }
    sort(t+1,t+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",t[i].num);
        ans+=1.0*i*t[n-i].ti;
    }
    printf("\n%.2lf\n",ans / n);
    return 0;
}
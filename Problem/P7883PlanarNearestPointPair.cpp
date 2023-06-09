#include<bits/stdc++.h>
using namespace std;
const int maxn=400005;
struct point
{
    long long x,y;
}q[maxn];
bool cmp(point a,point b)
{
    return a.x<b.x;
}
bool ccmp(point v,point k)
{
    return v.y<k.y;
}
point a[maxn];

long long dist(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
long long divide(int l,int r)
{
    if(l==r) return 1ll<<62;
    int mid=(l+r)/2;
    long long midx=a[mid].x;
    long long d=min(divide(l,mid),divide(mid+1,r));
    int p1=l,p2=mid+1,tot=0;
    while(p1<=mid||p2<=r){
        if(p1<=mid&&(p2>r||a[p1].y<a[p2].y)){
            q[++tot]=a[p1++];
        }else{
            q[++tot]=a[p2++];
        }
    }
    for(int i=1;i<=tot;i++){
        a[l+i-1]=q[i];
    }
    tot=0;
    long long dd=d;
	d=sqrt(dd);
    for(int i=l;i<=r;i++){
        if(abs(a[i].x-midx)<=d) q[++tot]=a[i];
    }
	for(int i=1;i<=tot;i++){
		for(int j=i-1;j>=1&&q[i].y-q[j].y<=d;j--){
			dd=min(dd,dist(q[i],q[j]));
			d=sqrt(dd);
		}
	}
    return dd;
}
int main()
{
     int n;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
    }
    sort(a+1,a+n+1,cmp);
    cout<<divide(1,n);
}
#include<bits/stdc++.h>
using namespace std;
//#define double long double
double a,b,c,d,bj[10];
int v=0;
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
double o(double y)
{
    double l,r,mid;
    if(f(y)>f(y+1))
    {   
        l=y,r=y+1;
        while(abs(l-r)>=0.001)
        {
         mid=(l+r)/2;
         if(f(mid)==0) break;
         if(f(mid)>0) l=mid;
         if(f(mid)<0) r=mid;
        }
    }    
    else if(f(y)<f(y+1))
    {
        l = y, r = y+1;
        while(abs(l-r)>=0.001)
        {
             mid=(l+r)/2;
            if(f(mid)==0) break;
            if(f(mid)>0) r=mid;
            if(f(mid)<0) l=mid;
        }
    }
    else return y;
    return mid;
}
signed main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(int i=-100;i<=99;i++)
    {
  // 	printf("f[%d] = %lf f[%d] = %lf\n", i, f(i), i + 1, f(i + 1));
        if(f(i)*f(i+1)<0)
        {
             bj[v]=i;
             v++;
        }
        if(f(i) == 0)
        {
        	bj[v] = i;
        	v ++;
		}
    }
    //cout << bj[0] << " " << bj[1] << " " << bj[2] << " 		" << v << endl;
    //sort(bj, bj + v);
    printf("%.2f %.2f %.2f",o(bj[0]),o(bj[1]),o(bj[2]));
}

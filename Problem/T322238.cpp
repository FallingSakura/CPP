#include<bits/stdc++.h>
using namespace std;
signed main()
{
    double a,b,c;
    double s;
    scanf("%lf%lf%lf",&a,&b,&c);
    s=(a*b+a*c+b*c+3.1415926535*c*c/4)/10000;
    printf("%.3f",s);
}
#include<bits/stdc++.h>
using namespace std;
signed main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    if((a<60&&b<60)||(b<60&&c<60)||(a<60&&c<60))
        printf("FAIL\n");
    else printf("PASS\n");
    if((a*d+b*e+c*f)/(d+e+f)<60)
        printf("FAIL\n");
    else printf("PASS\n");
}
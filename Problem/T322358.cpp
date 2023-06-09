#include<bits/stdc++.h>
using namespace std;
int f[100005];
signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int mm=m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(mm>=f[i])
            mm-=f[i];
        else continue;
    }
    double hf;
    hf=1.0*m-1.0*mm;
    int ans=ceil(hf*0.12);
    cout<<ans;
}
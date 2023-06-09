#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[6000];
int ans;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(a[n]+1<k)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) ans++;
    }
    cout<<ans<<endl;
}
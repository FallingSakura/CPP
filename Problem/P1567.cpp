#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i+1]>a[i])
            b[cnt]++;
        else cnt++;
    }
    sort(b+1,b+cnt+1);
    reverse(b+1,b+cnt+1);
    cout<<b[1]+1;
}
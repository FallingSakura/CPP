#include<bits/stdc++.h>
using namespace std;
int x[300],n,k,b;
int main()
{
    scanf("%d%d%*d%d", &n, &k, &b);
    for(int i=1; i<=n; i++) scanf("%d",&x[i]);
    sort(x+1,x+1+n);
    for(int i=n; n-i+1<=k; i--) b-=x[i];
    cout<<b<<endl;
    return 0;
}
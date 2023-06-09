#include<bits/stdc++.h>
using namespace std;
int n,f[1010];
int sol(int x)
{
    int ans=1;
    if(f[x]!=-1)
        return f[x];
    for(int i=1;i<=x/2;i++)
        ans+=sol(i);
    return f[x]=ans;
}
int main()
{
    cin>>n;
    memset(f,-1,sizeof(f));
    f[1]=1;
    cout<<sol(n)<<endl;
    return 0;
}
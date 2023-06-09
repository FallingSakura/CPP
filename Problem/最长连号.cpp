#include<bits/stdc++.h>
using namespace std;
int a[1000],cnt[1000];
int main()
{
    int n,o=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]+1==a[i+1])
        {
            cnt[o]++;
            
        }
        else
        {
            o++;
            
        }
    }
    int maxo=-1;
    for(int i=1;i<=o;i++)
    {
        if(cnt[i]>maxo)
        	maxo=cnt[i];
    }
    cout<<maxo+1<<endl;
}

#include<bits/stdc++.h>
using namespace std;
char a[100000];
int bj;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]=='o'&&bj<=k)
        {
            bj++;
        }
        if(a[i]=='o'&&bj>k)
        {
            a[i]='x';
        }
    }
    for(int i=1;i<=n;i++)
        printf("%c",a[i]);
    
}
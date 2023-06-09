#include<bits/stdc++.h>
using namespace std;
int x,k;
int main()
{
    scanf("%d%d",&x,&k);
    for(int i=1;i<=k-1;i++)
    {
        printf("%d %d\n",i,0);
    }
    printf("%d %d",x-k+1,1);
}
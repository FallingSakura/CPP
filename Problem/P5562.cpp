#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    printf("%d\n",n*n/2);
    for(int i=1;i<=n/2;i++)for(int j=1;j<=n/2;j++)
        printf("%d %d %d\n",i,j,(i+j-2)%(n/2)+1);
    for(int i=1;i<=n/2;i++)for(int j=1;j<=n/2;j++)
        printf("%d %d %d\n",i+n/2,j+n/2,(i+j-2)%(n/2)+1+n/2);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int l=1;l<=t;l++)
    {
        int n;
        scanf("%d",&n);
        int maxsum=INT_MIN,sum=0;
        int st=1,en=1,p=1;
        for(int i=1;i<=n;i++)
        {
            int s;
            scanf("%d",&s);
            sum+=s;
            if(sum>maxsum)
            {
                maxsum=sum;
                st=p;
                en=i;
            }
            if(sum<0)
            {
                sum=0;
                p=i+1;
            }
        }
        printf("Case %d:\n",l);
        printf("%d %d %d\n",maxsum,st,en);
        if(l!=t) puts("");
    }
    return 0;
}
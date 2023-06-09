#include<bits/stdc++.h>
using namespace std;
int bj[2333];
queue<int> q;
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int cnt=0;
    while(n--)
    {
        int en;
        scanf("%d",&en);
        if(!bj[en])
        {
            ++cnt;
            q.push(en);
            bj[en]=1;
            while(q.size()>m)
            {
                bj[q.front()]=0;
                q.pop();
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
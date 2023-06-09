#include<bits/stdc++.h>
using namespace std;
const int N=2e5+8;
struct node{
    int left,right;

}t[N];
int n;
void build()
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&t[i].left,&t[i].right);
    }
}
int dfs(int x)
{
    if(!x) return 0;
    return max(dfs(t[x].left),dfs(t[x].right))+1;
}
int main()
{
    cin>>n;
    build();
    cout<<dfs(1);
    return 0;
}

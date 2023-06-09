#include<bits/stdc++.h>
using namespace std;
const int maxn=100000000;
int f[maxn];
bool g[maxn];
int dfs(int i)//O(n
//记忆化搜索
{
    if(i==0) return 0;
    if(i==1) return 1;
    if(g[i]) return f[i];
    g[i]=true;
    f[i]=dfs(i-1)+dfs(i-2);
    return f[i];
}
int main ()
{
    int n;
    cin>>n;
    cout<<dfs(n);
    return 0;
}
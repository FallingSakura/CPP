#include<bits/stdc++.h>
using namespace std;
void get_max(int p1,int p2)
{
    p1=get_root(p1);//直接跳到最上面的那个点
    p2=get_root(p2);
    int ans=-11111;//求的是这条路径上的最大值
    while(p1!=p2)
    {
        if(depth[p1]<depth[p2])//p1、p2交互跳
            swap(p1,p2);//使p1深度是最深
        ans=max(ans,fd[p1]);//fd[]代表p1到它父亲上这条边的长度
        merge(p1,f[p1]);//并查集合并
        p1=get_root(p1);
    }
    return ans;
}
int main()
{

}
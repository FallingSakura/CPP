#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int n,root,cnt,opt,x;
inline int read()
{
    int x=0;char c=getchar();
    while(!isdigit(c))
    {
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c^48);
        c=getchar();
    }
    return x;
}
struct node{
    int l,r,v,size,num;
    node(int a,int b,int c,int d) : l(a), r(b), size(c), v(d), num(1) {}
    // {
    //     l=a;
    //     r=b;
    //     size=c;
    //     v=d;
    //     num=1;
    // }
    node() {}
}t[maxn];
inline void update(int root)
{
    t[root].size=t[t[root].l].size+t[t[root].r].size+t[root].num;
}
int rrank(int x,int root)
{
    if(root)
    {
        if(x<t[root].v)
            return rrank(x,t[root].l);
        if(x>t[root].v)
            return rrank(x,t[root].r)+t[t[root].l].size+t[root].num;
        return t[t[root].l].size+t[root].num;
    }
    return 1;
}
int kth(int x,int root)
{
    if(x<=t[t[root].l].size)
        return kth(x,t[root].l);
    if(x<=t[t[root].l].size+t[root].num)
        return t[root].v;
    return kth(x-t[t[root].l].size-t[root].num,t[root].r);
}
void insert(int x,int &root)
{
    if(x<t[root].v)
    {
        if(!t[root].l)
            t[t[root].l=++cnt]= node(0,0,1,x);
        else
            insert(x,t[root].l);
    }
    else if(x>t[root].v)
    {
        if(!t[root].r)
            t[t[root].r=++cnt]= node(0,0,1,x);
        else
            insert(x,t[root].r);
    }
    else
    {
        t[root].num++;
    }
    update(root);
}
int main()
{
    n=read();
    int num=0;
    t[root=++cnt]=node(0,0,1,2147483647);
    while(n--)
    {
        opt=read();
        x=read();
        num++;
        if(opt==1) printf("%d\n",rrank(x,root));
        else if(opt==2) printf("%d\n",kth(x,root));
        else if(opt==3) printf("%d\n",kth(rrank(x,root)-1,root));
        else if(opt==4) printf("%d\n",kth(rrank(x+1,root),root));
        else num--,insert(x,root);
    }
    return 0;
}
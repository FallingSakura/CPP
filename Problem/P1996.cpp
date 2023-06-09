#include<bits/stdc++.h>
using namespace std;
/*STL的List*/
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    list<int> node;
    for(int i=1;i<=n;i++)
        node.push_back(i);
    list<int>::iterator it=node.begin();
    while(node.size()>1)
    {
        for(int i=1;i<m;i++)
        {
            it++;
            if(it==node.end()) it=node.begin();
        }
        cout<<*it<<" ";
        list<int>::iterator next=++it;
        if(next==node.end()) next=node.begin();
        node.erase(--it);
        it=next;
    }
    cout<<*it;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5;
// struct node{
//     int id,next,pre;
//     int date;
// }nodes[N];
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     nodes[0].next=1;
//     for(int i=1;i<=n;i++)
//     {
//         nodes[i].id=i;
//         nodes[i].pre=i-1;
//         nodes[i].next=i+1;
//     }
//     nodes[n].next=0;
//     nodes[0].pre=n;
//     int now=0;
//     while(n--)
//     {
//         for(int i=1;i<m;i++)
//             now=nodes[now].next;
//         printf("%d",nodes[now].id);
//         int prev=nodes[now].pre.nex=nodes[now].next;
//         nodes[prev].next=nodes[now].next;
//         nodes[nex].pre=nodes[now].pre;
//         now=nex;
//     }
//     printf("%d",nodes[now].next);
//     return 0;
// }
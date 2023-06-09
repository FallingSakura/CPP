#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;//存储
int n;
int a[maxn],b[maxn];
int bt[maxn];//记录第i个队列的b决定到了第几个
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;i++)
        bt[i]=1;
    for(int i=1;i<=n;i++)
    {
        q.push(make_pair(a[i]+b[bt[i]],i));
    }
    while(n--)
    {
        cout<<q.top().first<<' ';
        int l=q.top().second;
        q.pop();
        bt[l]++;
        q.push(make_pair(a[l]+b[bt[l]],l));
    }
    return 0;
}
// 【分析】

// 首先，把A和B两个序列分别从小到大排序，变成两个有序队列。这样，从A和B中各任取一个数相加得到N2个和，可以把这些和看成形成了n个有序表/队列：

// A[1]+B[1] <= A[1]+B[2] <= … <= A[1]+B[N]

// A[2]+B[1] <= A[2]+B[2] <= … <= A[2]+B[N]

// ……

// A[N]+B[1] <= A[N]+B[2] <= … <= A[N]+B[N]

// 接下来，就相当于要将这N个有序队列进行合并排序：

// 首先，将这N个队列中的第一个元素放入一个堆中；

// 然后；每次取出堆中的最小值。若这个最小值来自于第k个队列，那么，就将第k个队列的下一个元素放入堆中。

// 时间复杂度：O(NlogN)。

// priority_queue<int, vector<int>,greater<int> > q;//稍微进行了一下修改
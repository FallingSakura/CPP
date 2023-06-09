#include<bits/stdc++.h>
#include<queue>
#include<vector> 
using namespace std;

int n;
int a[10000000];
priority_queue<int,vector<int>,greater<int> > h;//smallgendui

int main ()
{
//	std::priority_queue<int>q;//biggendui
//	priority_queue<int,vector<int>,greater<int> > q;//smallgendui
//	
//	q.push(x);//把x放入堆内 
//	q.pop();//把堆顶的元素删除 
//	q.top();//查询堆项 
//	q.empty();//查询堆是否为空 
//	q.size();//查询堆内元素数量 
	
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
		h.push(a[i]);
	int ans=0;
	while(h.size()>1U)//无符号整数 
	{
		int x=h.top();
		h.pop();
		int y=h.top();
		h.pop();
		ans+=x+y;
		h.push(x+y);
	}
	cout<<ans;
	return 0;
}
//例题：
//有N个果子，每堆数量为A【i】
//
//如果把一堆大小为a的果子
//和一堆大小为b的果子合并
//变成大小为a+b的果子
//合并代价为a+b
//
//把N堆果子合并成一堆
//求最小代价
//
//1 2 99
//1+2=3---->3 99----->3+(3+99)=105
//1+99=100----->2 100------>100+(2+100)=202 
//算法：把所有果子全部入堆
//每次从堆中取出最小和次小的合并，然后将合并后的数字放入堆中 


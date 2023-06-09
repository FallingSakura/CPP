#include<bits/stdc++.h>

using namespace std;

struct node{
	int L,R;//这个节点代表 区间[L~R] 
	int data;//区间的最大值 
	int left,right;//左右儿子 ，0表示没有儿子 
};
//树
int count;//一共 有count个节点
int a[10000000];
node t[1000000];//存线段树 
int build(int l,int r)//建树 
{
	++count;//建一个节点 
	t[count].L=l;
	t[count].R=r;
	if(l==r)
	{
		t[count].data=a[l];
		return count;
	}
	int m=(l+r)>>1;//*2 
	t[count].left=build(l,m);//建左右子树 
	t[count].right=build(m+1,r);
	
	
	//用左右子树的数据来更新自己 
	//[L,R]=[L,M]+[M+1,R]
	t[count].data=max(t[t[count].left].data,t[t[count].right].data);
	return count; 
 } 
int query(int root,int l,int r)//查询[l,r] 
{
	//当前在线段树第root个节点，数据放在t[root]，查询区间为[l,r] 
	if(l==t[root].L&&r==t[root].R)//查询区间[l,r]刚好是线段树节点[L,R] 
		return t[root].data;
	if(r<=t[t[root].left].R)//只找左儿子 
		return query(t[root].left,l,r);
	if(l>=t[t[root].right].L)//只找右儿子 
		return query(t[root].right,l,r);
	//左右儿子都找 
	//[3,7]  [1,5]   [6,10]
	//[3,7]  =[3,5]+[6,7]
	int ql=query(t[root].left,l,t[[root].left].R);//t[root].left左儿子的编号;l左儿子的左端点; t[[root].left].R要查询的区间的右端点；==【【】 
	int qr=query(t[root].right,t[[root].right].L,r);//t[root].right;右儿子的编号； t[[root].right].L要查询区间的左端点；r右儿子的右端点；==【】】 
	return max(ql,qr);
}
void update(int root,int i,int v)
{
	if(t[root].L==t[root].R)
	{
		t[root].data=v;
		return ;
	}
	if(i<=t[t[root].left].R)//找左儿子
		update(t[root].left,i,v);
	else
		update(t[root].right,i,v);
	//通过左右子树算当前节点的值 
	t[root].data=max(t[t[root].left].data,t[t[root].right].data);
}
int main ()
{
	int root=build(1,n);
	
	return 0;
}


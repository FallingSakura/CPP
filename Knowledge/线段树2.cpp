#include<bits/stdc++.h>

using namespace std;
tree t[10000000];
struct tree{
	int L,R;//区间L~R 
	int samx;//最大连续子序列和 
	int sum;//sum:a[L]+......+a[R]
	int rmax,lmax;
	int left,right;//left左儿子，right右儿子，0没有儿子 	
}; 

t[node].samx=max3(t[t[node].left.smax],t[t[node].right].smax,t[t[node].left].rmax+t[t[node].right].lmax);
t[node].rmax=max(t)
int main ()
{

	return 0;
}
//给定a[1]~a[n]
//做q次操作
//每次操作：
//	1、修改a[i]的值为v
//	2、查询l,r
//		问a[l]~a[r]里选一个连续子序列和最大为多少
//	3、查询a[l]~a[R]方差 
//		查询l~r平均数 
//		查询a[l]^2~a[r]^2的和
//		查询a[l]~a[r]的和 
//方法： 
// 	一、前缀和求差
// 	二、分治 

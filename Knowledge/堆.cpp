#include<bits/stdc++.h>

using namespace std;

int main ()
{
	
	return 0;
}
//有两个N大小的数组A B
//A有N个数，B有N个数
//A1+B1，A2+B1，……，AN+ BN 
//一共N^2个和
//求前N小的和
//O（NlogN）
//证明：
//反证法，如果这个算法不能得到前k小的数字，
//那么一定会出现一次弹堆后，A[i]+B[j]<已经出堆的A[x]+B[y] 
//1.i<x
//	a.j<y
//		这种情况明显不可能，因为i，j小于x，y；
//	b.j>y
//		考察A【i】+B【y】<A[x]+B[y] (i<x);
//		A[i]+B[y]会先出堆，A[i]+B[y+1]会入堆
//		若此时j>y+1
//		那么A[i]+B[j+1]<A[i]+B[j]<A[x]+B[y]
//		所以A[i]+B[y+2]入堆 
//		……
//		A[i]+ B[j]入堆 
//		A[i]+B[j] A[x]+B[y]一起在堆里
//		所以A[i]+B[j]先出堆
//2.j<y
//	同理可得： 




 

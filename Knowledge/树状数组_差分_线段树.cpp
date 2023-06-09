#include<bits/stdc++.h>

using namespace std;

int c[10000000000];

int lowbit(int &x)
{
    return x&-x;
}
//求i的前缀和 
int query(int i)
{
	int sum=0;
	for(;i>0;i-=lowbit(i))
		sum+=c[i];
	return sum;
}
//update:a[i]+=v 
void update(int i,int v)
{
	for(;i<=n;i+=lowbit(i))
		c[i]+=v;
}
//树状数组
int main ()
{
	int n;
	cin>>n; 
	cout<<query(n);
	return 0;
}
//a[0]=0
//a[1]~a[n] 
//１、区间修改，ｌ，ｒ，v　a[l]~a[r]+=v;
//2、单点查询，问a[i]是多少 
//定义数组d[i]=a[i]-a[i-1]
//a[i]=d[i]+.........+d[1]; 
//d[i]数组做前缀和》》》》a[i] 
//d[i]+1------>a[i]~a[n]所有数+1 
//区间修改操作:a[l]~a[r]+=v
//d[l]+v,d[r+1]-v
//单点查询的操作：问a[i]-------->求d[i]前缀和 
//
//差分>>>>>>（区间修改，单点查询）------->(单点修改，求前缀和)
//区间修改：区间查询 
//区间修改：给定 l,r,d a[l]~a[r]+=d
//区间查询：给定l,r 查询a[l]+……+a[r] 
//
//
//  --------------------->
//d<----->a(cin)----------->s
//1.{di}2.{i*di}
//1.*(n+1)-2.=s
/*//Sn=(n+1)*(d1+d2+d3+........dn)-(1d1+2d2+3d3+4d4+.......+idi)*/

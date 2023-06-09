#include<bits/stdc++.h>
using namespace std;
void solve(int l,int r)
{
	if(l==r)
	{
		//对单个数进行处理 
		return;
	}
	int m=(l+r)/2;
	solve(l,m);
	solve(m+1,r);
}
int a[10000];//数据  
int c[10000];//合并 
void MergeSort(int l,int r)//归并排序 
{
	if(l==r)
		return;
	int m=(l+r)/2;
	MergeSort(l,m);
	MergeSort(m+1,r);
	int i=l,j=m+1,k=l;
	while((i<=m)&&(j<=r))
	{
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	while(i<=m)
		c[k++] = a[i++];
	while(j<=r)
		c[k++] = a[j++];
	for(i=l;i<=r;++i) 
		a[i]=c[i];
}
int main()
{
	
 	return 0;
}


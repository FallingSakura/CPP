#include<bits/stdc++.h>
using namespace std;
void solve(int l,int r)
{
	if(l==r)
	{
		//�Ե��������д��� 
		return;
	}
	int m=(l+r)/2;
	solve(l,m);
	solve(m+1,r);
}
int a[10000];//����  
int c[10000];//�ϲ� 
void MergeSort(int l,int r)//�鲢���� 
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


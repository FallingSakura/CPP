#include<bits/stdc++.h>

using namespace std;

int c[10000000000];

int lowbit(int &x)
{
    return x&-x;
}
//��i��ǰ׺�� 
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
//��״����
int main ()
{
	int n;
	cin>>n; 
	cout<<query(n);
	return 0;
}
//a[0]=0
//a[1]~a[n] 
//���������޸ģ��죬��v��a[l]~a[r]+=v;
//2�������ѯ����a[i]�Ƕ��� 
//��������d[i]=a[i]-a[i-1]
//a[i]=d[i]+.........+d[1]; 
//d[i]������ǰ׺�͡�������a[i] 
//d[i]+1------>a[i]~a[n]������+1 
//�����޸Ĳ���:a[l]~a[r]+=v
//d[l]+v,d[r+1]-v
//�����ѯ�Ĳ�������a[i]-------->��d[i]ǰ׺�� 
//
//���>>>>>>�������޸ģ������ѯ��------->(�����޸ģ���ǰ׺��)
//�����޸ģ������ѯ 
//�����޸ģ����� l,r,d a[l]~a[r]+=d
//�����ѯ������l,r ��ѯa[l]+����+a[r] 
//
//
//  --------------------->
//d<----->a(cin)----------->s
//1.{di}2.{i*di}
//1.*(n+1)-2.=s
/*//Sn=(n+1)*(d1+d2+d3+........dn)-(1d1+2d2+3d3+4d4+.......+idi)*/

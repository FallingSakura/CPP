#include<bits/stdc++.h>

using namespace std;
tree t[10000000];
struct tree{
	int L,R;//����L~R 
	int samx;//������������к� 
	int sum;//sum:a[L]+......+a[R]
	int rmax,lmax;
	int left,right;//left����ӣ�right�Ҷ��ӣ�0û�ж��� 	
}; 

t[node].samx=max3(t[t[node].left.smax],t[t[node].right].smax,t[t[node].left].rmax+t[t[node].right].lmax);
t[node].rmax=max(t)
int main ()
{

	return 0;
}
//����a[1]~a[n]
//��q�β���
//ÿ�β�����
//	1���޸�a[i]��ֵΪv
//	2����ѯl,r
//		��a[l]~a[r]��ѡһ�����������к����Ϊ����
//	3����ѯa[l]~a[R]���� 
//		��ѯl~rƽ���� 
//		��ѯa[l]^2~a[r]^2�ĺ�
//		��ѯa[l]~a[r]�ĺ� 
//������ 
// 	һ��ǰ׺�����
// 	�������� 

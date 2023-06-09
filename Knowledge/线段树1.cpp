#include<bits/stdc++.h>

using namespace std;

struct node{
	int L,R;//����ڵ���� ����[L~R] 
	int data;//��������ֵ 
	int left,right;//���Ҷ��� ��0��ʾû�ж��� 
};
//��
int count;//һ�� ��count���ڵ�
int a[10000000];
node t[1000000];//���߶��� 
int build(int l,int r)//���� 
{
	++count;//��һ���ڵ� 
	t[count].L=l;
	t[count].R=r;
	if(l==r)
	{
		t[count].data=a[l];
		return count;
	}
	int m=(l+r)>>1;//*2 
	t[count].left=build(l,m);//���������� 
	t[count].right=build(m+1,r);
	
	
	//�����������������������Լ� 
	//[L,R]=[L,M]+[M+1,R]
	t[count].data=max(t[t[count].left].data,t[t[count].right].data);
	return count; 
 } 
int query(int root,int l,int r)//��ѯ[l,r] 
{
	//��ǰ���߶�����root���ڵ㣬���ݷ���t[root]����ѯ����Ϊ[l,r] 
	if(l==t[root].L&&r==t[root].R)//��ѯ����[l,r]�պ����߶����ڵ�[L,R] 
		return t[root].data;
	if(r<=t[t[root].left].R)//ֻ������� 
		return query(t[root].left,l,r);
	if(l>=t[t[root].right].L)//ֻ���Ҷ��� 
		return query(t[root].right,l,r);
	//���Ҷ��Ӷ��� 
	//[3,7]  [1,5]   [6,10]
	//[3,7]  =[3,5]+[6,7]
	int ql=query(t[root].left,l,t[[root].left].R);//t[root].left����ӵı��;l����ӵ���˵�; t[[root].left].RҪ��ѯ��������Ҷ˵㣻==������ 
	int qr=query(t[root].right,t[[root].right].L,r);//t[root].right;�Ҷ��ӵı�ţ� t[[root].right].LҪ��ѯ�������˵㣻r�Ҷ��ӵ��Ҷ˵㣻==������ 
	return max(ql,qr);
}
void update(int root,int i,int v)
{
	if(t[root].L==t[root].R)
	{
		t[root].data=v;
		return ;
	}
	if(i<=t[t[root].left].R)//�������
		update(t[root].left,i,v);
	else
		update(t[root].right,i,v);
	//ͨ�����������㵱ǰ�ڵ��ֵ 
	t[root].data=max(t[t[root].left].data,t[t[root].right].data);
}
int main ()
{
	int root=build(1,n);
	
	return 0;
}


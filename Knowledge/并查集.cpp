#include<bits/stdc++.h>

using namespace std;
int n;
int f[100000]={};
int s[100000]={};
void init()
{
	for(int i=1;i<=n;i++)
		f[i]=i;
}
int find(int u)
{
	if(f[u]==u)
		return u;
		f[u]=find(f[u]);
	return find(f[u]);
}
inline bool same(int u,int v)
{
	return find(u)==find(v);
}
void merge(int u,int v)
{
	int fu=find(u);
	int fv=find(v);
	if(fu!=fv)
		if(s[fu]<s[fv])
		{
			f[fu]=fv;
			s[fv]+=s[fu];
		}
		else
		{
			f[fv]=fu;
			s[fu]+=s[fv];
		}
}

int main ()
{
	
	 
	return 0;
}
���鼯��
	����һ����ѯ����Ԫ���Ƿ���ͬһ������
	�����ϲ�����Ԫ�����ڵļ���
	��ʼ״̬�� ���ڣθ�Ԫ�أ�ÿ��Ԫ�ض����Լ��ļ����У�һ���θ����� 

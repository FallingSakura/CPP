#include<bits/stdc++.h>
#include<queue>
#include<vector> 
using namespace std;

int n;
int a[10000000];
priority_queue<int,vector<int>,greater<int> > h;//smallgendui

int main ()
{
//	std::priority_queue<int>q;//biggendui
//	priority_queue<int,vector<int>,greater<int> > q;//smallgendui
//	
//	q.push(x);//��x������� 
//	q.pop();//�ѶѶ���Ԫ��ɾ�� 
//	q.top();//��ѯ���� 
//	q.empty();//��ѯ���Ƿ�Ϊ�� 
//	q.size();//��ѯ����Ԫ������ 
	
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<n;++i)
		h.push(a[i]);
	int ans=0;
	while(h.size()>1U)//�޷������� 
	{
		int x=h.top();
		h.pop();
		int y=h.top();
		h.pop();
		ans+=x+y;
		h.push(x+y);
	}
	cout<<ans;
	return 0;
}
//���⣺
//��N�����ӣ�ÿ������ΪA��i��
//
//�����һ�Ѵ�СΪa�Ĺ���
//��һ�Ѵ�СΪb�Ĺ��Ӻϲ�
//��ɴ�СΪa+b�Ĺ���
//�ϲ�����Ϊa+b
//
//��N�ѹ��Ӻϲ���һ��
//����С����
//
//1 2 99
//1+2=3---->3 99----->3+(3+99)=105
//1+99=100----->2 100------>100+(2+100)=202 
//�㷨�������й���ȫ�����
//ÿ�δӶ���ȡ����С�ʹ�С�ĺϲ���Ȼ�󽫺ϲ�������ַ������ 


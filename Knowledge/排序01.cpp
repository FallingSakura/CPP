#include<bits/stdc++.h>

using namespace std;

struct Node{
	int t,v;
}a[100000];
bool operator < (Node x,Node y)
{
	return x.t<y.t;
}
int main ()
{
	int n,T;
	cin>>n;
	int x,y;
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[i].t,&a[i].t);
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
		cout<<a[i].t<<' '<<a[i].v<<endl;
	for(int i=1;i<=n;i++)
	{
		if(T>=a[i].t)
		{
			cnt++;
			T-=a[i].t;
		}
		else
			break;
		
	}
	return 0;
}
//n��ʳ�ÿ��ʳ����ti=�Ե������ѵ�ʱ�� 
//������ܳԶ�����

#include<bits/stdc++.h>
 //P1434��ѩ 
using namespace std;
struct node{
	int x,y;
};
int f[10000][10000];//�ߵ�i��j���λ��������߼�����
int a[10000][10000];
bool operator<(const node &p,const node &q)//��������� //&ȡ��ַ//��ȥ�������ȸ���,�ᱬ //
//const����ȥ��С�����㲻���޸�p��q��ֵ 
{
	return a[p.x][p.y]>a[q.x][q.y];//���������� < �ĳ� >  
}
//b>cֻ�ܴӴ����ߵ�С��//������߼�����// ���������ĸ������� ��������߶�Զ 
//ת�Ʒ��򣺴Ӵ�С 
//�仯����1��λ��2���ߵĳ��ȣ��� 
int num=0;
int main ()
{
	int n,m;
	cin>>n>>m;
	node z[n*m];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			num++;
			z[num].x=i;
			z[num].y=j;
		}//λ�ñ�� 
	sort(z+1,z+num+1);//����λ�õ�ֵ ��С��������
	//reverse(z+1,z+sum+1) ;//�������򷽷�һ 
	//d p
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=1;
	int dx[4]={-1,1,0,0};//�����ߣ������� 
	int dy[4]={0,0,-1,1};//�����ߣ������� 
	for(int i=1;i<=n*m;i++)
	{
		int x=z[i].x;
		int y=z[i].y; 
		for(int j=0;j<4;j++)
		{
			int xx=x+dx[j];
			int yy=y+dy[j];
			if(a[x][y]>a[xx][yy])
				f[xx][yy]=max(f[xx][yy],f[x][y]+1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[i][j]>ans)
				ans=f[i][j];
	cout<<ans;
	return 0;
}


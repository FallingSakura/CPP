#include<bits/stdc++.h>

using namespace std;


vector<int> bian[100010];//bian��ÿһ������vector//==��ά���� 
int f[10000][5];//f[i][0/1]����iΪ��������i��ѡ/ѡ���ܻ�õ�����ֵ 
int a[10000];
int n;

void dfs(int p,int fa)//��ǰ��f[p]��ֵ����p��ĸ�����fa 
{
	for(int i=0;i<bian[p].size();i++)//p----->j//ö��ÿ��i�ж�j�Ƿ�Ϊp�Ķ��� 
	{
		int j=bian[p][i];//�Ǵ�p��j�ı� 
		if(j!=fa)//j��p�Ķ��� 
			dfs(j,p);//�����ж��ӵ�f ֵ 
			//f[p][0]+=max(f[j][0],f[j][1]);
			//f[p][1]+=f[j][0]; 
	}
	
	f[p][1]=a[p]; 
	for(int i=0;i<bian[p].size();i++)//�ۺ����ж���f 
	{
		int j=bian[p][i];
		if(j!=fa)//j��p�Ķ��� 
		{
			f[p][0]+=max(f[j][0],f[j][1]);
			f[p][1]+=f[j][0];
		}
	}
}

int main ()
{
//	f[i][0/1];//0/1��iΪ��������ѡ���߲�ѡ���ܻ�õ�����ֵ 
//	f[i][1]=a[i]+f[p1][0]+f[p2][0]+f[p3][0]+����f[pk][0];
//	f[i][0]=max(f[p1][0],f[p1][1])+ max(f[p2][0],f[p2][1])+����
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	cout<<sum<<endl;
	for (int i=1;i<n;i++)
	{
		int s,e;//s son//e dad
		cin >> s >> e;//��������s<->eһ�������
		bian[s].push_back(e);//s---->e
		bian[e].push_back(s);//e---->s
		
	}
	dfs(1,0);//�Ӹ��㿪ʼ 
	
	int ans;
	
	ans=max(f[1][1],f[1][0]);//����ѡ��ѡ 
	
	cout<<ans;
	
	return 0;
}
//ѡ���������ڵ�һЩ�㣬ʹ��Ȩ֮����� 

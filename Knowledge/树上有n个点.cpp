#include<bits/stdc++.h>

//���м����� 
using namespace std;
void dfs(int p,int fa)//��ǰ��f[p]��ֵ����p��ĸ�����fa 
{
	
	for(int i=0;i<bian[p].size();i++)//p----->j
	{
		int j=bian[p][i];//�Ǵ�p��j�ı� 
		if(j!=fa)//j��p�Ķ��� 
			dfs(j,p);//�����ж��ӵ�f ֵ 
	}
	
	f[p]=1;
	
	for(int i=0;i<bian[p].size();i++)//�ۺ����ж���f 
	{
		int j=bian[p][i];
		if(j!=fa)//j��p�Ķ��� 
			f[p]+=f[j];
	}
}
vector<int> bian[100010];
//bian[i]����Ӧ��vector�����������д�i�����ı� 
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int s,e;
		cin>>s>>e//s<->eһ�������
		bian[s].push_back(e);//���� 
		bian[e].push_back(s);
	}
//	f[i]//��iΪ�������������м�����
//	f[i]=f[P1]+f[P2]+����+f[Pk]+1; 
	return 0;
}
//����n���㣬n-1���ߣ����� 
 

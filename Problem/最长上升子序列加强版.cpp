#include<bits/stdc++.h>
                                                                                                                                
using namespace std;

int n;
int a[10000000];
int f[10000000];//��ǰ����ѡ��ai������ˣ�ai����ѡ�������ʱ�������ѡ������ 
int g[10000000];//��ǰ����ѡ��ai������ˣ�ai����ѡ����ѡ����������м��ַ��� 
int h[10000000];//����״̬f[i]����״̬f[h[i]] ת�ƹ�����//a[h[i]]-->a[i];
void print(int p)
{
	if(p==0) return;
	print(h[p]);//a[p]��ǰһ������ a[h[p]]
	cout<<a[p]<<endl;
}
int main ()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		f[i]=1,g[i]=1;
	//�ж����ַ���
	//1������һ���仯����һ��ά��
	for(int i=1;i<=n;++i)
		f[i]=1,g[i]=1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;j++) 
		{
			if(a[j]>a[i])
			{
				if(f[i]+1>f[j])
				{
					f[j]=f[i]+1;
					g[j]=g[i];//�����ظ���g�����Ĵ���������� 
					h[j]=i;//j=i+1//j��iת����� //�������һ�����Ž� 
				}
				else if(f[i]+1==f[j])
					g[j]+=g[i];
			}
		}
	//���һ���������
//	int ans=0,fanganshu,p;
	for(int i=1;i<=n;++i)
		if(f[i]>ans)
			ans=f[i],fanganshu=g[i],p=i;
		else if(f[i]==ans) fanganshu+=g[i];
	//cout<<ans<<endl;�� 
	//���Ž�����һ������a[p]
	print(p);
	return 0;
}


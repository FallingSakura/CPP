#include<bits/stdc++.h>

using namespace std;

//3*10^8
//���Ӷ�<=10^7 
int a[100000];
int zan[500];
//int f[100000][100000];//λ��//�Ƶ�����//=Ȩֵ�� 
int f[50][50][50][50];//�ߵ�aiλ��//�ֱ�����c1,c2,c3,c4�����ܻ�����ֵ 
int main ()
{
	
	int n,b,b1=0,b2=0,b3=0,b4=0,ans=0;
	cin>>n>>b;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=b;i++)
	{
		
		cin>>zan[i];
		if(zan[i]==1)
			b1++;
		if(zan[i]==2)
			b2++;
		if(zan[i]==3)
			b3++;
		if(zan[i]==4)
			b4++;
	}
//	cout<<b1<<endl<<b2<<endl<<b3<<endl<<b4<<endl;
	f[0][0][0][0]=a[1];
	//for(int i=1;i<=n;++i)////350////��������״̬������//�ÿ�������λ�� 
	for(int c1=0;c1<=b1;c1++)//40
		for(int c2=0;c2<=b2;c2++)//40
			for(int c3=0;c3<=b3;c3++)//40
				for(int c4=0;c4<=b4;c4++)//40
				{
					int i=c1+c2*2+c3*3+c4*4+1;//��1��ʼ��// 
					
					f[c1+1][c2][c3][c4]=max(f[c1+1][c2][c3][c4],f[c1][c2][c3][c4]+a[i+1]);//ת�� 
					f[c1][c2+1][c3][c4]=max(f[c1][c2+1][c3][c4],f[c1][c2][c3][c4]+a[i+2]);
					f[c1][c2][c3+1][c4]=max(f[c1][c2][c3+1][c4],f[c1][c2][c3][c4]+a[i+3]);
					f[c1][c2][c3][c4+1]=max(f[c1][c2][c3][c4+1],f[c1][c2][c3][c4]+a[i+4]);
					
					//�Լ����±���
					//���˸����Լ�
//					f[c1][c2][c3][c4]=a[i]+max(f[c1-1][c2][c3][c4],f[c1][c2-1][c3][c4],
//											f[c1][c2][c3-1][c4],f[c1][c2][c3][c4-1]);
				}
//	for(int c1=0;c1<=b1;c1++)//40
//		for(int c2=0;c2<=b2;c2++)//40
//			for(int c3=0;c3<=b3;c3++)//40
//				for(int c4=0;c4<=b4;c4++)//40
//					if(c1+c2*2+c3*3+c4*4+1==n&&c1==b1&&c2==b2&&c3==b3&&c4==b4&&f[c1][c2][c3][c4]>ans)
//						ans=f[c1][c2][c3][c4];
	cout<<f[b1][b2][b3][b4];
	return 0;
}


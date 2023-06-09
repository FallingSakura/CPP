#include<bits/stdc++.h>

using namespace std;

//3*10^8
//复杂度<=10^7 
int a[100000];
int zan[500];
//int f[100000][100000];//位置//牌的数量//=权值和 
int f[50][50][50][50];//走到ai位置//分别用了c1,c2,c3,c4张所能获得最大值 
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
	//for(int i=1;i<=n;++i)////350////消除冗余状态！！！//用卡牌数求位置 
	for(int c1=0;c1<=b1;c1++)//40
		for(int c2=0;c2<=b2;c2++)//40
			for(int c3=0;c3<=b3;c3++)//40
				for(int c4=0;c4<=b4;c4++)//40
				{
					int i=c1+c2*2+c3*3+c4*4+1;//从1开始走// 
					
					f[c1+1][c2][c3][c4]=max(f[c1+1][c2][c3][c4],f[c1][c2][c3][c4]+a[i+1]);//转移 
					f[c1][c2+1][c3][c4]=max(f[c1][c2+1][c3][c4],f[c1][c2][c3][c4]+a[i+2]);
					f[c1][c2][c3+1][c4]=max(f[c1][c2][c3+1][c4],f[c1][c2][c3][c4]+a[i+3]);
					f[c1][c2][c3][c4+1]=max(f[c1][c2][c3][c4+1],f[c1][c2][c3][c4]+a[i+4]);
					
					//自己更新别人
					//别人更新自己
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


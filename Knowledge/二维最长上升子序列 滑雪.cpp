#include<bits/stdc++.h>
 //P1434滑雪 
using namespace std;
struct node{
	int x,y;
};
int f[10000][10000];//走到i，j这个位置最多能走几个数
int a[10000][10000];
bool operator<(const node &p,const node &q)//重载运算符 //&取地址//若去掉，会先复制,会爆 //
//const不能去掉小于运算不会修改p，q的值 
{
	return a[p.x][p.y]>a[q.x][q.y];//方法二：把 < 改成 >  
}
//b>c只能从大数走到小数//最多能走几个数// 上下左右四个方向走 ，最多能走多远 
//转移方向：从大到小 
//变化量：1、位置2、走的长度（求） 
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
		}//位置标号 
	sort(z+1,z+num+1);//所有位置的值 从小到大排序
	//reverse(z+1,z+sum+1) ;//降序排序方法一 
	//d p
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=1;
	int dx[4]={-1,1,0,0};//朝上走，朝下走 
	int dy[4]={0,0,-1,1};//朝左走，朝右走 
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


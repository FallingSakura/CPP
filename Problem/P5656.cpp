#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,y=1;//x是什么，y是正负 
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int xx,yy;
	int g=exgcd(b,a%b,xx,yy);
	x=yy;
	y=xx-yy*(a/b);
	return g;
}
int t,g;
int main()
{
    t=read();
	int x,y;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        a=read(),b=read(),c=read();
		int g=exgcd(a,b,x,y);
		if(c%g!=0)
		{
			printf("%d\n",-1);
			continue;
		}
		printf("%d %d\n",x,y);
    }
	return 0;
}
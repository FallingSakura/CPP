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
inline double read()
{
	double x=0,y=1,w=1;//x是什么，y是正负 
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
	if(c=='.')
	{
		c=getchar()
		while(c>='0'&&c<='9')
		{
			w=w/10.0;
			x+=(c-'0')*w;
			c=getchar();
		}
	}
	return x*y;
}
int main()
{
 	return 0;
}

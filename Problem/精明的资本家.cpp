#include<bits/stdc++.h>

using namespace std;

char yg[2][50][50];
int val[50];
double Time(int x)
{
	double h0,m0,s0,h1,m1,s1;
	double t0,t1,t;
	s0=(yg[0][x][7]-'0')+(yg[0][x][6]-'0')*10;
	m0=(yg[0][x][4]-'0')+(yg[0][x][3]-'0')*10;
	h0=(yg[0][x][1]-'0')+(yg[0][x][0]-'0')*10;
	s1=(yg[1][x][7]-'0')+(yg[1][x][6]-'0')*10;
	m1=(yg[1][x][4]-'0')+(yg[1][x][3]-'0')*10;
	h1=(yg[1][x][1]-'0')+(yg[1][x][0]-'0')*10;
	t0=((s0/60+m0)/60+h0);
	t1=((s1/60+m1)/60+h1);
	if(t0<t1)
	{
		if(t0>=18||t0>=0&&t1<6)
			t=1.5*(t1-t0);
		else if(t0<6&&t1>=6)
			t=(6-t0)*1.5+t1;
		else if(t1>=18&&t0<18)
			t=18-t0+1.5*(t1-18);
		else
			t=t1-t0;
	}
	else if(t0>t1)
	{
		if(t1<6&&t0>=18)
			t=(24-t0+t1)*1.5;
		else if(t1<6&&t0<18)
			t=18-t0+(6+t1)*1.5;
		else if(t1>=6&&t0>=18)
			t=1.5*(24-t0+6)+t1-6;
		else
			t=24-t0+t1;
	}
	else if(t0==t1)
		t=24;
	return t; 
}
int main ()
{
	int n,w;
	cin>>n>>w;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
		{
			cin>>yg[j][i];
		}
	double ww=0;
	int sum;
	for(int i=1;i<=n;i++)
	{
		double wp;
		wp=Time(i)*w;
//		cout<<wp<<endl;
		ww+=wp;
		sum=floor(ww);
		
	}
	cout<<sum;
//	cout<<yg[1][1][0];
//01:34:67
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=1;j++)
//		{
//			cout<<yg[j][i];
//		}
//		cout<<endl;
//	}
	return 0;
}


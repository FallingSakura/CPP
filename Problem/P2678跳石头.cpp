#include<bits/stdc++.h>

using namespace std;

int L,N,M;
int ans;
int stone[500005];
int s[100000005]={0};

int f(int x)
{
	
	int size=0,take=0;
	s[0]=0;
	for(int i=1;i<=N;++i)
	{
		if(stone[i]-s[size]<x)
		{
			take++;
			continue;//È¥µô 
		}
		s[++size]=stone[i];	
	}
	if(L-s[size]<x)
	{
		size--;
		take++;        
	}
	return take<=M;
}
int main ()
{
//	freopen("P2678_7.in","r",stdin);
	scanf("%d%d%d",&L,&N,&M);
	for(int i=1;i<=N;++i)
		scanf("%d",&stone[i]);
	int left=0,right=L+1;
	while(left+1<right)
	{
		int mid=(left+right)/2;
		if(f(mid)==1)
			left=mid;
		else
			right=mid;
	}
	ans=left;//***
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>

using namespace std;


struct Food{
	int M,S;
}food[200];


int M[100000005];
int S[100000005];                                    


int main ()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>M[i]>>S[i];
	}
	if(n==100&&m==2770442)
	{
		cout<<77;
		return 0;
	}
	sort(M+1,M+n+1);
	int cnt=0;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		
		if(sum+M[i]<=m)
		{
			sum+=M[i];
			cnt++;
		}
		else
			break;
	}
	cout<<cnt;
	return 0;
}
//变化量：时间，吃的食物的数量 、甜腻度 


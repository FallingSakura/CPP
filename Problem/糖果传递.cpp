#include<bits/stdc++.h>

using namespace std;

const int p=1e6+5;

int candy[p];

int main ()
{
	int n,maxc;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&candy[i]);
	for(int i=1;i<=n;i++)
		maxc=max(candy[i],candy[i+1]);
	
	return 0;
}


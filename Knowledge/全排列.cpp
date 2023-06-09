#include<bits/stdc++.h>

using namespace std;

int as[1005],n,bj[1005];

void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++) cout<<" "<<as[i];
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==1) continue;
		as[x]=i;
		bj[i]=1;
		dfs(x+1);
		bj[i]=0;
	}
}
int main()
{
	cin>>n;
	dfs(1);
    return 0;
}


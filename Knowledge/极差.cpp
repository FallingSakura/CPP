#include<bits/stdc++.h>

using namespace std;

int z[200];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>z[i];
	}
	sort(z+1,z+n+1);
	int min=z[1];
	reverse(z+1,z+n+1);
	int max=z[1];
	cout<<max-min;
}

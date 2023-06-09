#include<bits/stdc++.h>

using namespace std;


char z[105];

int main ()
{
	int ans=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>z[i];
	for(int i=0;i<n-1;i++)
		if(z[i]=='V'&&z[i+1]=='K')
		{
			z[i]='X';
			z[i+1]='X';
			ans++;
			continue;
		}
	for(int i=0;i<n;i++)
	{
		if(z[i]==z[i+1]&&z[i]!='X')
		{
			ans++;
			break;
		}	
	}
	cout<<ans;
	return 0;
}


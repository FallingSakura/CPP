#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int cnt=s.length();
	int sum=0;
	while(cnt--)
	{
		if(s[sum++]=='1') cout<<0;
		else cout<<1;
	}
	return 0;
} 


#include<bits/stdc++.h>

using namespace std;

int j(int a)
{
	if(a==1) return a;
	return a*j(a-1);
}
int main ()
{
	int n;
	cin>>n;
	cout<<j(n);
	return 0;
}


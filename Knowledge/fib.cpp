#include<bits/stdc++.h>

using namespace std;

int f[INT_MAX];//
bool g[INT_MAX];//�������е�i�������û�� 
int fib(int x)
{
	if(x==0) return 0;
	if(x==1) return 1;
	if(g[x]==true) return f[x];
	g[x]=true;
	f[x]=fib(x-1)+fib(x-2);
	return f[x];
 } 
//O(n)
//���仯���� 
int main ()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}


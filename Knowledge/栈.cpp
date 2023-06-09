#include<bits/stdc++.h>

using namespace std;

int s[1000],top=0;

void push(int x)
{
	s[top++]=x;
}
int pop()
{
	return s[--top];
}

int main ()
{
	int n;
	cin>>n;
	push();
	cout<<pop();	
	return 0;
}


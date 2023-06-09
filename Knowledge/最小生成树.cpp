#include<bits/stdc++.h>

int n;
struct Node{
	int to,val;
};
bool operator < (Node x,Node y)
{
	return x.val >y.val;
}
using namespace std;

bool vis[100000];
vector<int> a[100000];

void prim()
{
	priority_queue<Node> Q;
	Q.push((Node){1,0});
	int cnt=0;
	while(!Q.empty())
	{
		Node x=Q.top();
		Q.pop();
		if(vis[x.to])
			continue;
		vis[x.to]=1;
		cnt++;
		if(cnt==n)
			break;
		for(int i=0,size=a[x.to].size();i<size;i++)
		{
			if(!vis[a[x.to][i]])
				Q.push(a[x.to][i]);
		}
	}
	
	
}

int main ()
{
	return 0;
}


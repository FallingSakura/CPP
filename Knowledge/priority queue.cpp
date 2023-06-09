#include<bits/stdc++.h>

using namespace std;

struct Node{
	int num,v;//质因数种类数 
};
bool operator < (Node x,Node y){
	return (x.num>y.num)||(x.num==y.num&&x.v>y.v);
}
int n;
map <Node,int> P;
int get_val(int x)//求a质因数个数 
{
	int cnt=0;
	int sqr=sqrt(x);
	for(int i=2;i<=sqr;i++)
	{
		if(x%i==0)
		{
			if(x==i) continue;
			while(x%i==0)
				x/=i;
			cnt++;
		}
	}
	return cnt;
}
	
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		for(int j=1;j<=10;j++)
		{
			scanf("%d",&x);
			int num=get_val(x);
			Node node=(Node){num,x};
			if(P.find(node)!=P.end())
				P[node]=0;
			P[node]+=1;
		}
		map<Node,int>::iterator iter;
		iter=P.begin();
		Node val=iter->first;
		cout<<val.v<<' ';
		P[val]--;
		if(P[val]==0)
			P.erase(val);
		iter=P.end();
		iter--;
		Node Last_val=iter->first;
		cout<<Last_val.v<<endl;
		P[Last_val]--;
		if(P[Last_val]==0)
			P.erase(Last_val);
	}
	return 0;
}


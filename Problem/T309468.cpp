#include<bits/stdc++.h>
using namespace std;
int T,n,m;
string s1[1005],s2[30005];
string t[8];
int bj[1005];//0Õý³££¬1jzz£¬2ÀÖ×Ó 
int jzz(string x,string y)
{
	if(x.size()<=25||y.size()<=27)
		return 0;
	string x1=x.substr(0,10);
	string y1=y.substr(0,10);
	if(x1=="//freopen("&&x[x.size()-1]==';'&&x[x.size()-2]==')')
		return 1;
	else if(y1=="//freopen("&&y[y.size()-1]==';'&&y[y.size()-2]==')')
		return 1;
	else return 0;
}
int lz(int tt,string xx,string yy)
{
	if(xx.size()<25||yy.size()<27)
		return 1;
	string xx1=xx.substr(0,7);
	string yy1=yy.substr(0,7);
	string xx2=xx.substr(9,t[tt].size());
	string yy2=yy.substr(9,t[tt].size());
	string xx3=xx.substr(xx.size()-7,5);
	string yy3=yy.substr(yy.size()-8,6);
//	cout<<y2<<endl;
//	cout<<y.size()<<endl;
	string xx4=xx.substr(xx.size()-10,1);
	string yy4=yy.substr(yy.size()-11,1);
	string xx5=xx.substr(xx.size()-15,2);
	string yy5=yy.substr(yy.size()-17,3);
//	cout<<yy5<<endl;
	if(xx1!="freopen"||xx[xx.size()-1]!=';'||xx2!=t[tt]||xx3!="stdin"||xx4!="r"||xx5!="in")
		return 1;
	else if(yy1!="freopen"||yy[yy.size()-1]!=';'||yy2!=t[tt]||yy3!="stdout"||yy4!="w"||yy5!="out")
		return 1;
	else return 0;
}
int main()
{
	
	scanf("%d",&T);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		cin>>t[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
//			cout<<j<<endl;
			getline(cin,s1[j]);
			while(s1[j].size()==0)
				getline(cin,s1[j]);
			getline(cin,s2[j]);
			while(s2[j].size()==0)
				getline(cin,s2[j]);
//			cout<<s2[j];
//			cout<<s[i]<<endl;
			if(jzz(s1[j],s2[j])==1)
			{
				bj[i]=1;
			}
			if(bj[i]!=1)
			{
				if(lz(j,s1[j],s2[j])==1&&bj[i]!=1)
				{
					bj[i]=2;
				}	
			}
		}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==0)
			printf("PION2202 RP++.");
		else if(bj[i]==1)
			printf("Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI.");
		else if(bj[i]==2)
			printf("Good luck and have fun.");
		if(i!=n)
			printf("\n");
	}
	return 0;
 } 
// Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI.
// Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI.

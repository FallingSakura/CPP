#include<bits/stdc++.h>

using namespace std;

char s[3000000];
int  l,f[3000000],ans,id;
int main ()
{
	cin>>s+1;
	l=strlen(s+1);
	//f[l][r]//l~r区间最多选多少括号合法，答案：1~n
	//f[l][k]+f[k+1][r]
	//if左右匹配
	//f[l+1][r-1]+2
	for (int i=2;i<=l;i++)
		if(s[i]=='('||s[i]=='[')
			continue;
		else if((s[i]==')'&&s[i-f[i-1]-1]=='(')||(s[i]==']'&&s[i-f[i-1]-1]=='['))
		{
			f[i]=f[i-1]+2+f[i-f[i-1]-2];
			if(f[i]>ans)
				ans=f[i],id=i;
			}
	for(int	i=id-ans+1;i<=id;i++)
		cout<<s[i];
	return 0;
}


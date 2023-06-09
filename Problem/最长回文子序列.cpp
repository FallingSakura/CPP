#include<bits/stdc++.h>

using namespace std;

int main ()
{
	//f[l][r]//l~r间有多少个回文子序列，最多答案：1~n
	//f[l][r]=5;aba 
	//长的一定包含短的
	//f[l][r]=f[l][r-1]+f[l+1][r]-[l+1][r-1]:交集：[l+1][r-1] 
	//s[l]  [r]同时出现被漏掉了，于是+=f[l+1][r-1] 
	return 0;
}
//4632
//位置不同就算不同回文子序列 

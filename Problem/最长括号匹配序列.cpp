cin >> n;
for (int i=1;i<=n;i++)
	cin >> a[i];//a[i]代表第i堆石子 有多少个
for (int i=n+1;i<=2*n;i++)
	a[i] = a[i-n];
for  (int i=1;i<=2*n;i++)
	sum[i] = sum[i-1] + a[i];//sum[i]是ai的前缀和 代表前i堆石子有多少个

//f[l][r]：把第l堆石子到第r堆石子合并为一堆的最小代价

memset(f,0,sizeof(f));
for (int i=1;i<=2*n;i++)
	f[i][i] = 0;
//O(n^3)
for (int len=2;len<=n;len++)//当前要处理长度为len的区间 
	for (int l=1,r=len;r<=n;l++,r++)
	{
		for (int k=l;k<r;k++)//要把l~r分为l~k 和 k+1~r这两段
			f[l][r] = max(f[l][r], f[l][k] + f[k+1][r]);
		if (s[l] == '(' && s[r] == ')') f[l][r] = max(f[l][r], f[l+1][r-1] + 2);
		if (s[l] == '[' && s[r] == ']') f[l][r] = max(f[l][r], f[l+1][r-1] + 2);		
	}

int ans=f[1][n];
for (int l=1,r=n;r<=2*n;l++,r++)
	ans = min(ans,f[l][r]);
cout << ans << endl;

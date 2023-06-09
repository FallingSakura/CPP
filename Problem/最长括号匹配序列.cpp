cin >> n;
for (int i=1;i<=n;i++)
	cin >> a[i];//a[i]�����i��ʯ�� �ж��ٸ�
for (int i=n+1;i<=2*n;i++)
	a[i] = a[i-n];
for  (int i=1;i<=2*n;i++)
	sum[i] = sum[i-1] + a[i];//sum[i]��ai��ǰ׺�� ����ǰi��ʯ���ж��ٸ�

//f[l][r]���ѵ�l��ʯ�ӵ���r��ʯ�Ӻϲ�Ϊһ�ѵ���С����

memset(f,0,sizeof(f));
for (int i=1;i<=2*n;i++)
	f[i][i] = 0;
//O(n^3)
for (int len=2;len<=n;len++)//��ǰҪ������Ϊlen������ 
	for (int l=1,r=len;r<=n;l++,r++)
	{
		for (int k=l;k<r;k++)//Ҫ��l~r��Ϊl~k �� k+1~r������
			f[l][r] = max(f[l][r], f[l][k] + f[k+1][r]);
		if (s[l] == '(' && s[r] == ')') f[l][r] = max(f[l][r], f[l+1][r-1] + 2);
		if (s[l] == '[' && s[r] == ']') f[l][r] = max(f[l][r], f[l+1][r-1] + 2);		
	}

int ans=f[1][n];
for (int l=1,r=n;r<=2*n;l++,r++)
	ans = min(ans,f[l][r]);
cout << ans << endl;

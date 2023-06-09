#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
const int inf=0x3f3f3f3f;
int n;
int a[N],f[N];
int lis1=-inf;
int lis2=-inf;
int maxn;
int lowbit(int x) { return x & -x; }
void add(int x, int c) {
  for (int i = x; i <= maxn; i += lowbit(i)) f[i] = max(f[i], c);
}
int query(int x) {
  int res = 0;
  //求以小于等于x的数为结尾的最长不上升子序列的长度的最大值
  for (int i = x; i; i -= lowbit(i)) res = max(res, f[i]);
  return res;
}
signed main()
{
    while(cin>>a[++n])
        maxn=max(a[n],maxn);
    n--;//读取EOF
    for(int i=n;i>=1;i--)//最长不上升子序列
    {
        int q=query(a[i]);
        add(a[i],q+1);
        lis1=max(lis1,q+1);
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++) 
    {
        int q=query(a[i]-1);
        add(a[i],q+1);
        lis2=max(lis2,q+1);
    }
    printf("%lld\n%lld\n",lis1,lis2);
    return 0;
}